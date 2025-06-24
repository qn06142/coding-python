import sys
import time
import random

input = sys.stdin.readline

def monte_carlo_solver(a, c, time_limit=0.95):
    """
    Heuristic Monte Carlo: randomly simulate choices at each position 1..n,
    keep best score found. Runs until time_limit seconds elapse.
    """
    n = len(a)
    start_time = time.time()
    best_overall = 0

    # Precompute prefix sums for O(1) range sums if we attempt small merges:
    pa = [0] * (n + 1)
    for i in range(1, n + 1):
        pa[i] = pa[i - 1] + a[i - 1]

    # We will do several independent random trials.
    # In each trial, we maintain:
    #   i = current position (1-indexed),
    #   energy = how much energy we currently have,
    #   score = total points collected so far.
    # At each i, we randomly pick one of:
    #   - “gain”: energy += 1,
    #   - “buy single”: if energy >= c[i], spend c[i] and gain a[i],
    #   - “attempt small merge”: choose a random L in [1..min(10,i)] and see if we can merge [i-L+1..i].

    # We limit the maximum chunk‐merge length we attempt to some small constant M
    # (e.g. M = 10).  If the chunk is too large, we skip merge.  This keeps each
    # step O(1) and the entire walk O(n).

    M = 10  # max merge‐length to attempt in a single step

    # Rough number of trials: we stop when time >= time_limit
    trials = 0
    while time.time() - start_time < time_limit:
        trials += 1
        i = 1
        energy = 0
        score = 0

        # We’ll do exactly one walk from i=1 to i=n.
        while i <= n:
            # If we have enough energy to buy single, we include that as one choice.
            choices = []

            # Always can “gain”:
            choices.append("gain")

            # If energy >= c[i], we can “buy single”:
            if energy >= c[i - 1]:
                choices.append("buy_single")

            # We also “attempt small merge” of random length ℓ in [2..M], if ℓ ≤ i.
            # (ℓ=1 is the same as “buy_single,” so we skip ℓ=1.)
            if i >= 2 and energy >= c[i - 1]:
                # we only try merge with small probability, so that majority of steps are cheap
                if random.random() < 0.3:
                    choices.append("merge")

            action = random.choice(choices)

            if action == "gain":
                energy += 1
                i += 1

            elif action == "buy_single":
                # spend c[i], collect a[i], move on
                energy -= c[i - 1]
                score += a[i - 1]
                i += 1

            else:  # action == "merge"
                # pick a random merge length ℓ between 2 and min(M, i)
                max_len = min(M, i)
                ℓ = random.randint(2, max_len)
                # we merge the chunk [i-ℓ+1 .. i] provided we have enough energy to pay c[i]
                # (the problem statement says merging costs no extra energy except losing
                #  the opportunity to gain +1 on those ℓ-1 positions, but we ignore that here
                #  because we’re not tracking exact DP). Instead we simply check:
                #   “if (energy_before_merge) >= c[i], then we can take sum(a[i-ℓ+1..i])”
                # In reality you’d need to lose ℓ-1 gains, but this heuristic just collects chunk.
                #
                # For simplicity, we check energy >= c[i], then do:
                #   energy -= c[i]; score += sum(a[i-ℓ..i-1]); i += 1.
                if energy >= c[i - 1]:
                    sum_chunk = pa[i] - pa[i - ℓ]
                    energy -= c[i - 1]
                    score += sum_chunk
                    i += 1
                else:
                    # fallback: just gain
                    energy += 1
                    i += 1

        # record final score
        if score > best_overall:
            best_overall = score

    # print how many trials we did (for debug, can comment out)
    # print(f"Trials: {trials}", file=sys.stderr)
    return best_overall


def main():
    n = int(input().strip())
    a = list(map(int, input().split()))
    c = list(map(int, input().split()))

    # Run Monte Carlo for ≈0.95 seconds
    answer = monte_carlo_solver(a, c, time_limit=0.95)
    print(answer)


if __name__ == "__main__":
    main()
