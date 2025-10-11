#!/usr/bin/env python3
import os
import math
import numpy as np
import gymnasium as gym
from gymnasium import ActionWrapper
from sb3_contrib import RecurrentPPO  # use RecurrentPPO for LSTM support
from stable_baselines3.common.vec_env import SubprocVecEnv
from stable_baselines3.common.callbacks import CheckpointCallback, BaseCallback
from multiprocessing import Process, get_start_method
import multiprocessing as mp

# ----------------------------------------------------------------------------
# Globals & paths
# ----------------------------------------------------------------------------
THROTTLE_VALUE      = 0.2
RESUME_PATH         = "./resume/ppo_carracing_resume1.zip"
CHECKPOINT_DIR      = "./checkpoints/"
TENSORBOARD_LOG     = "./ppo_carracing_tensorboard/"
PREVIEW_MODEL_PATH  = "./preview/latest_model.zip"

# ----------------------------------------------------------------------------
# Action wrappers to combine or check gas/brake
# ----------------------------------------------------------------------------
class ThrottleBrakeWrapper(ActionWrapper):
    """
    Convert a single throttle-brake scalar into separate gas/brake channels.
    Input action = [steer, tb], where tb in [-1, 1]: positive=gas, negative=brake.
    """
    def __init__(self, env: gym.Env):
        super().__init__(env)
        # action_space remains inherited for model (2-dim)
        self.env = env

    def action(self, action: np.ndarray) -> np.ndarray:
        steer = np.clip(action[0], -1.0, 1.0)
        tb = np.clip(action[1], -1.0, 1.0)
        gas = float(max(tb, 0.0))
        brake = float(max(-tb, 0.0))
        return np.array([steer, gas, brake], dtype=np.float32)

class BrakeCheckWrapper(ActionWrapper):
    """
    Track if brake channel is ever used during rollout.
    Prints summary at the end of each episode.
    """
    def __init__(self, env: gym.Env):
        super().__init__(env)
        self.brake_count = 0
        self.step_count = 0

    def action(self, action: np.ndarray) -> np.ndarray:
        # action is now 3-dim after ThrottleBrake
        if action[2] > 1e-3:
            self.brake_count += 1
        self.step_count += 1
        return action

    def reset(self, **kwargs):
        if self.step_count > 0:
            usage = self.brake_count / self.step_count
            print(f"[Brake usage this epi: {usage:.2%} ({self.brake_count}/{self.step_count})]")
        self.brake_count = 0
        self.step_count = 0
        return self.env.reset(**kwargs)

# ----------------------------------------------------------------------------
# Preview worker process
# ----------------------------------------------------------------------------
def preview_worker(model_path: str):
    env = gym.make("CarRacing-v3", continuous=True, render_mode="human")
    # Wrap BrakeCheck then ThrottleBrake so BrakeCheck sees 3-d action
    env = BrakeCheckWrapper(env)
    env = ThrottleBrakeWrapper(env)
    model = RecurrentPPO.load(model_path, env=env, device='cpu')

    obs, info = env.reset()
    lstm_states = None
    episode_starts = np.array([True])
    try:
        while True:
            action, lstm_states = model.predict(
                obs,
                state=lstm_states,
                episode_start=episode_starts,
                deterministic=True,
            )
            obs, reward, terminated, truncated, info = env.step(action)
            episode_starts = np.array([terminated or truncated])
            if terminated or truncated:
                obs, info = env.reset()
            env.render()
    except KeyboardInterrupt:
        pass
    finally:
        env.close()

# ----------------------------------------------------------------------------
# AsyncPreviewCallback
# ----------------------------------------------------------------------------
class AsyncPreviewCallback(BaseCallback):
    def __init__(self, preview_freq: int, verbose: int = 0):
        super().__init__(verbose)
        self.preview_freq = preview_freq
        self.last_preview = 0
        self.process: Process | None = None

    def _start_preview(self):
        if self.process and self.process.is_alive():
            self.process.kill()
        self.process = Process(
            target=preview_worker,
            args=(PREVIEW_MODEL_PATH,),
            daemon=True
        )
        self.process.start()
        if self.verbose > 0:
            print(f"[Spawned preview process @ {self.num_timesteps} steps]")

    def _on_step(self) -> bool:
        if (self.num_timesteps - self.last_preview) >= self.preview_freq:
            self.last_preview = self.num_timesteps
            self.model.save(PREVIEW_MODEL_PATH)
            self._start_preview()
        return True

    def _on_training_end(self) -> None:
        if self.process and self.process.is_alive():
            self.process.terminate()
        if self.verbose > 0:
            print("[Training done — preview process terminated]")

# ----------------------------------------------------------------------------
# Environment factory
# ----------------------------------------------------------------------------
def make_train_env():
    env = gym.make("CarRacing-v3", continuous=True)
    # Wrap BrakeCheck then ThrottleBrake so BrakeCheck sees 3-d action
    env = BrakeCheckWrapper(env)
    env = ThrottleBrakeWrapper(env)
    return env

# ----------------------------------------------------------------------------
# main()
# ----------------------------------------------------------------------------
def main():
    os.makedirs(os.path.dirname(RESUME_PATH), exist_ok=True)
    os.makedirs(CHECKPOINT_DIR, exist_ok=True)
    os.makedirs(os.path.dirname(PREVIEW_MODEL_PATH), exist_ok=True)

    num_cpu = 8
    print(f"Using {num_cpu} parallel environments (start method: {get_start_method()})")

    train_env = SubprocVecEnv([make_train_env for _ in range(num_cpu)])

    policy_kwargs = {
        "lstm_hidden_size": 256,
        "n_lstm_layers": 1,
        "shared_lstm": False,
    }

    if os.path.isfile(RESUME_PATH):
        print(f"Resuming from {RESUME_PATH}")
        model = RecurrentPPO.load(
            RESUME_PATH,
            env=train_env,
            device='auto',
            policy_kwargs=policy_kwargs,
            verbose=1
        )
    else:
        print("Starting new LSTM-based model")
        model = RecurrentPPO(
            policy="CnnLstmPolicy",
            env=train_env,
            verbose=1,
            learning_rate=2.5e-4,
            n_steps=4096,
            batch_size=512,
            ent_coef=0.005,
            clip_range=0.2,
            tensorboard_log=TENSORBOARD_LOG,
            policy_kwargs=policy_kwargs,
        )

    checkpoint_cb = CheckpointCallback(
        save_freq=max(100_000 // num_cpu, 1),
        save_path=CHECKPOINT_DIR,
        name_prefix="rppo_carrace",
    )
    preview_cb = AsyncPreviewCallback(preview_freq=100000, verbose=1)

    try:
        model.learn(
            total_timesteps=2_000_000,
            callback=[checkpoint_cb, preview_cb],
        )
    except KeyboardInterrupt:
        print("\n🚨 KeyboardInterrupt caught! Saving resume checkpoint…")
        model.save(RESUME_PATH)
        print(f"Saved resume to {RESUME_PATH}. Restart to continue.")
    else:
        print("\n✅ Training complete! Saving final models…")
        model.save(RESUME_PATH)
        model.save("rppo_carracing_v3_lstm")

    train_env.close()

if __name__ == '__main__':
    mp.set_start_method('spawn', force=True)
    main()