import subprocess
import random
import string
import random

def gen(n, q, max_value=10** 9):
    """
    Generates a test case for the problem.

    Parameters:
    n (int): Initial size of the array (1 ≤ n ≤ 10^5).
    q (int): Number of operations (1 ≤ q ≤ 10^5).
    max_value (int): Maximum absolute value of array elements (default: 10^9).

    Returns:
    str: A string representation of the test case to be piped to stdin.
    """
    # Generate initial array of size n
    array = [random.randint(-max_value, max_value) for _ in range(n)]
    
    operations = []
    for _ in range(q):
        op_type = random.choice(["A", "D", "L", "R", "Q"])
        if op_type == "A":
            # Add operation: A x
            x = random.randint(-max_value, max_value)
            operations.append(f"A {x}")
        elif op_type == "D":
            # Delete operation: D
            operations.append("D")
        elif op_type == "L":
            # Move left operation: L
            operations.append("L")
        elif op_type == "R":
            # Move right operation: R
            operations.append("R")
        elif op_type == "Q":
            # Query operation: Q l r
            l = random.randint(1, n)
            r = random.randint(l, n)  # Ensure l ≤ r
            operations.append(f"Q {l} {r}")
    
    # Construct the test case string
    test_case = f"{n} {q}\n"
    test_case += " ".join(map(str, array)) + "\n"
    test_case += "\n".join(operations) + "\n"
    
    return test_case

def generate_test_case():
    n = 10
    m = random.randint(1, 100)
    return gen(n, m)
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
    executable1 = './csphn_dynamicsum1'
    executable2 = './csphn_dynamicsum'
    tests = 0
    while True:
        test_case = generate_test_case()

        #print(test_case)
        output1 = run_program(executable1, test_case)
        output2 = run_program(executable2, test_case)
        tests += 1
        if output1 != output2:
            print(f"Test case: {test_case}")
            print(f"Output of correct: {output1}")
            print(f"Output of {executable2}: {output2}")
            break
        print("PASSED", tests)

if __name__ == "__main__":
    main()
