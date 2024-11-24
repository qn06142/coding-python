import random

def generate_test_case(t, max_n, max_value):
    result = []
    result.append(f"{t}")
    
    for _ in range(t):
        n = random.randint(1, max_n)
        a = [random.randint(-max_value, max_value) for _ in range(n)]
        result.append(f"{n}")
        result.append(" ".join(map(str, a)))
    
    return "\n".join(result)

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
    executable1 = './csphn_lt_grobot1'
    executable2 = './csphn_lt_grobot'
    tests = 0
    while True:
        while True:
            try:
                test_case = generate_test_case(t=1, max_n=5, max_value=10)
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
