import subprocess
import random
import string

def generate_test_case():
    n = 100
    
    # Define bounds for coordinates (i, j, k)
    MAX_I = 10 # Maximum value for i and j (0 <= i, j <= 10^6)
    MAX_K = 10  # Maximum value for k (1 <= k <= 10^6)

    testcase = []
    ls = set()
    # Generate n rectangles
    for _ in range(n):
        l = random.randint(1, 10)
        while l in ls:
            l = random.randint(1, 10)
        ls.add(l)
        c = random.randint(1, 10)
        testcase.append(' '.join(str(i) for i in (l, c)))
    
    # Return as a single string with newline
    return f"{n}\n" + "\n".join(testcase)
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
    executable1 = './hnoi2021_r2_triacu1'
    executable2 = './hnoi2021_r2_triacu'
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

        tests += 1
        if output1 != output2:
            print(f"Test case: {test_case}")
            print(f"Output of correct: {output1}")
            print(f"Output of {executable2}: {output2}")
            break
        print("PASSED", tests)

if __name__ == "__main__":
    main()
