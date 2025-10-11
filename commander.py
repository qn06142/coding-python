import socket
import cv2
import numpy as np
import math
import time

HOST = '0.0.0.0'
PORT = 8000
TARGET_WIDTH, TARGET_HEIGHT = 512, 512
COLOR_REDUCTION = 1
DIFF_THRESHOLD = 100  # adjust as needed: pixel change magnitude threshold

def resize_image_to_fit(img, target_w, target_h):
    h, w = img.shape[:2]
    scale = min(target_h / h, target_w / w)
    new_size = (math.ceil(w * scale), math.ceil(h * scale))
    return cv2.resize(img, new_size)

def get_diff_pixels(ref, current, threshold=DIFF_THRESHOLD, color_reduction=1):
    if color_reduction > 1:
        ref_cmp = (ref // color_reduction) * color_reduction
        current_cmp = (current // color_reduction) * color_reduction
    else:
        ref_cmp = ref
        current_cmp = current

    diff = np.abs(ref_cmp.astype(np.int16) - current_cmp.astype(np.int16))
    diff_sum = np.sum(diff, axis=-1)
    mask = diff_sum >= threshold
    indices = np.argwhere(mask)
    values = current[mask]
    ref[mask] = values
    return indices, values, ref

def send_frame(conn, commands: str):
    data = commands.encode()
    conn.sendall(len(data).to_bytes(4, 'big'))
    conn.sendall(data)

if __name__ == '__main__':
    # 1) Setup server
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind((HOST, PORT))
    server_socket.listen(1)
    print(f"Listening on {HOST}:{PORT}")
    conn, addr = server_socket.accept()
    print(f"Connected by {addr}")

    # 2) Open video source
    cap = cv2.VideoCapture("/home/wheatley/Alohaii - Heart Of Glass (feat. Rachie) [Music Video] [f6FRYyOYNhA].webm")
    if not cap.isOpened():
        raise RuntimeError("Failed to open source.")

    # 3) Initial frame for resolution & ref buffer
    ret, frame = cap.read()
    if not ret:
        raise RuntimeError("Failed to read initial frame.")
    frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    frame_resized = resize_image_to_fit(frame, TARGET_WIDTH, TARGET_HEIGHT)
    TARGET_WIDTH, TARGET_HEIGHT = frame_resized.shape[1], frame_resized.shape[0]
    ref = np.zeros_like(frame_resized)

    # 4) Send resolution to client
    conn.sendall(f"RESO {TARGET_WIDTH} {TARGET_HEIGHT}".encode())

    # Get input FPS and compute fixed period
    fps = cap.get(cv2.CAP_PROP_FPS) or 30.0
    period = 1.0 / fps
    print(f"Input FPS: {fps:.2f} → period {period:.4f}s")

    # 5) Main loop with fixed timestep + FPS print
    next_frame_time = time.time()
    frame_times = []
    average_over = 30  # number of frames for running average

    try:
        while True:
            # wait until it’s time for the next frame
            now = time.time()
            sleep_t = next_frame_time - now
            if sleep_t > 0:
                time.sleep(sleep_t)
            else:
                # if we're behind, catch up
                next_frame_time = now

            start = time.time()
            ret, frame = cap.read()
            if not ret:
                break

            # Process and diff
            frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            frame_resized = resize_image_to_fit(frame_rgb, TARGET_WIDTH, TARGET_HEIGHT)
            diffs, values, ref = get_diff_pixels(ref, frame_resized, color_reduction=COLOR_REDUCTION)

            # Build DRAW commands
            parts = []
            for (y, x), (r, g, b) in zip(diffs, values):
                r, g, b = (int(i) for i in (r, g, b))
                color_int = (r << 16) | (g << 8) | b
                parts.append(f"DRAW {x} {y} {color_int}")
            if parts:
                payload = '\n'.join(parts)
                send_frame(conn, payload)

            # Optional: display locally
            # display_frame = cv2.cvtColor(ref, cv2.COLOR_RGB2BGR)
            # cv2.imshow("thing", display_frame)
            # if cv2.waitKey(1) & 0xFF == ord('q'):
            #     break

            # Measure elapsed and print FPS
            elapsed = time.time() - start
            if elapsed > 0:
                inst_fps = 1.0 / elapsed
                print(f"FPS (inst): {inst_fps:.2f}")

            frame_times.append(elapsed)
            if len(frame_times) > average_over:
                frame_times.pop(0)
            avg_fps = len(frame_times) / sum(frame_times)
            print(f"FPS (avg over {len(frame_times)}): {avg_fps:.2f}")

            # schedule next frame
            next_frame_time += period

    finally:
        print("Closing resources.")
        conn.close()
        server_socket.close()
        cap.release()
        cv2.destroyAllWindows()
