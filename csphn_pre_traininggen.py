import subprocess
import random
import string

def generate_test_case():
    n = 10000
    q = 10000
    a = ''.join(random.choice(string.ascii_uppercase) for i in range(0, n))
    query = '\n'.join(random.choice(string.ascii_uppercase) + " " + random.choice(("L", "R")) for i in range(0, q))
    return f"{n} {q}\n{a}\n{query}"
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
    executable1 = './csphn_pre_training1'
    executable2 = './csphn_pre_training'
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
        print(len(output1))
        for i in zip(output1, output2):
            print(*i)
        tests += 1
        if output1 != output2:
            print(f"Test case: {test_case}")
            print(f"Output of correct: {output1}")
            print(f"Output of {executable2}: {output2}")
            break
        print("PASSED", tests)

if __name__ == "__main__":
    main()
