import subprocess
import random
import string

def generate_test_case():
    n = 20
    m = 10
    k = random.randint(1, (n ** 2) * (m ** 2))
    a = ' '.join(str(random.randint(1, 10)) for i in range(0, n))
    b = ' '.join(str(random.randint(1, 10)) for i in range(0, m))
    return f"{n} {m} {k}\n{a}\n{b}"
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
    executable1 = './sumkmax1'
    executable2 = './sumkmax'
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
