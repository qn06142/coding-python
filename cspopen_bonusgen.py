import subprocess
import random
import string

def generate_test_case():
    n = m = 15
    testcase = []
    for i in range(0, n):
        row = []
        for j in range(0, m):
            row.append(random.randint(0, 1))
        testcase.append(' '.join(str(i) for i in row))
    return f"{n} {m}\n{'\n'.join(testcase)}"
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
    executable1 = './cspopen_bonus1'
    executable2 = './cspopen_bonus'
    tests = 0
    while True:
        while True:
            try:
                test_case = generate_test_case()
                break
            except:
                continue
        #print(test_case)
        print("corr")
        output1 = run_program(executable1, test_case)
        print("test")
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
