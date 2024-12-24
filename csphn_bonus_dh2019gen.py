import subprocess
import random
import string

def generate_test_case():
    m = 10000
    n = 10000
    k = random.randint(1, 10)
    x = random.randint(1, m)
    y = random.randint(1, n)
    u = random.randint(x, m)
    v = random.randint(y, n)
    return ' '.join(str(i) for i in (m, n, k, x, y, u, v))
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
    executable1 = './csphn_bonus_dh20191'
    executable2 = './csphn_bonus_dh2019'
    tests = 0
    while True:
        test_case = generate_test_case()
        print(test_case)
        output1 = run_program_py(executable1, test_case)
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
