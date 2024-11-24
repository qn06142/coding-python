import subprocess
import random
import string

def generate_test_case():
    n = random.randint(1, 10**2)  # Number of rectangles (1 <= n <= 10^5)
    testcase = []
    testcase1 = []
    # Generate n rectangles
    for _ in range(n):
        testcase.append(str(random.randint(1, 10)))
    for _ in range(n):
        testcase1.append(str(random.randint(1, 10)))
    
    # Return as a single string with newline
    return f"{n}\n" + "\n".join(testcase) + "\n" + "\n".join(testcase1)
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
    executable1 = './present1'
    executable2 = './present'
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
