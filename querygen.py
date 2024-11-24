import subprocess
import random
import string
import random

def generate_test_case():
    # Define constraints
    N = random.randint(1, 10000)  # For testing, we can use a smaller value of N
    K = random.randint(1, N)    # K should be <= N
    P = random.randint(1, 500)   # For testing, limit P to smaller values

    # Generate the array of length N with random values between 0 and 1
    arr = [random.randint(0, 1) for _ in range(N)]

    # Generate the queries
    queries = []
    for _ in range(P):
        query_type = random.choice(['!', '?'])
        queries.append(query_type)

    # Format the test case as a single string
    test_case = f"{N} {K} {P}\n"
    test_case += ' '.join(map(str, arr)) + "\n"
    test_case += ' '.join(queries)

    return test_case
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
    executable1 = './querybrute'
    executable2 = './query'
    tests = 0
    while True:
        while True:
            try:
                test_case = generate_test_case()
                break
            except:
                continue
        #print(test_case)
        output1 = run_program(executable1, test_case)
        output2 = run_program(executable2, test_case)
        print(output1, output2)
        tests += 1
        if output1 != output2:
            print(f"Test case: {test_case}")
            print(f"Output of correct: {output1}")
            print(f"Output of {executable2}: {output2}")
            break
        print("PASSED", tests)

if __name__ == "__main__":
    main()
