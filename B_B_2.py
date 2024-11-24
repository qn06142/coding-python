import random
import matplotlib.pyplot as plt

def brute_force_solution(n, a):
    min_k = float('inf')
    max_k = -float('inf')
    
    # Calculate range for k (from minimum to maximum possible scores)
    current_score = 0
    for i in range(n):
        current_score += a[i]
        min_k = min(min_k, current_score)
        max_k = max(max_k, current_score)
    min_k + max(0, min_k)
    # Brute force simulate for each possible k in the range
    k_values = list(range(min_k, max_k))
    scores = []
    
    for k in k_values:
        score = 0
        current_score = 0
        reached_k = False  # Flag to track if score has ever reached or exceeded k
        for i in range(n):
            current_score += a[i]
            if current_score >= k:
                reached_k = True
            if reached_k and current_score < k:
                current_score = k  # Only clamp score to k if it has been reached before
            score = current_score
        scores.append(score)
    
    return k_values, scores

def generate_random_testcase(n, low=-10**9, high=10**9):
    """Generate a random test case with n elements."""
    return [random.randint(low, high) for _ in range(n)]

# Set up the parameters
n = 10000  # Same length for all test cases
num_testcases = 1  # Number of random test cases

# Generate random test cases
testcases = [generate_random_testcase(n, -10 ** 2, 10 ** 2) for _ in range(num_testcases)]

# Plot the results for all test cases
plt.figure(figsize=(12, 8))

for idx, testcase in enumerate(testcases):
    k_values, scores = brute_force_solution(n, testcase)
    plt.plot(k_values, scores, marker='o', label=f'Test {idx+1}')
import matplotlib.style as mplstyle
mplstyle.use('fast')
# Customize plot
plt.title(f"Score changes with k for {num_testcases} random test cases (n={n})")
plt.xlabel("k (threshold value)")
plt.ylabel("Final Score")
plt.grid(True)
plt.legend(loc='upper left', bbox_to_anchor=(1,1))
plt.tight_layout()
plt.show()
