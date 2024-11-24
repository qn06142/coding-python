import random
from itertools import permutations

def generate_test_case():
    # Generate a random list of 26 integers between 0 and 10 for each letter's max count
    return [random.randint(0, 3) for _ in range(26)]

def is_valid(counts):
    # Check if all counts are unique and non-zero
    counts = [count for count in counts if count > 0]
    return len(counts) == len(set(counts))


def brute_force_solution(max_counts):
    chars = 'abcdefghijklmnopqrstuvwxyz'
    best_string = ""
    
    # Generate all possible count combinations within the max constraints
    possible_counts = [list(range(max_count + 1)) for max_count in max_counts]
    
    # Try all combinations where each character count meets the uniqueness constraint
    for counts in permutations([count for sublist in possible_counts for count in sublist], 26):
        if is_valid(counts):
            # Build string from valid counts
            candidate_string = "".join(chars[i] * counts[i] for i in range(26))
            if len(candidate_string) > len(best_string):
                best_string = candidate_string
    
    return best_string


import subprocess
import random
import string


def run_program(executable, input_data):
    # Run the executable with the given input data
    process = subprocess.Popen([executable], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate(input=input_data.encode())
    return stdout.decode().strip()
def run_program_py(executable, input_data):
    # Run the executable with the given input data
    process = subprocess.Popen(executable, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate(input=input_data.encode())
    return stdout.decode().strip()
def main():
    executable2 = './strmaker'
    tests = 0
    while True:
        while True:
            try:
                test_case = generate_test_case()
                break
            except:
                continue
        output1 = len(brute_force_solution(test_case))
        output2 = len(run_program(executable2, ' '.join(str(x) for x in test_case)))

        tests += 1
        if output1 != output2:
            print(f"Test case: {test_case}")
            print(f"Output of correct: {output1}")
            print(f"Output of {executable2}: {output2}")
            break
        print("PASSED", tests)

if __name__ == "__main__":
    main()
