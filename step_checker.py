import subprocess
import random
import string

def generate_test_case(n_max=10**5, q_max=10**5, a_max=10**4):
    # Random number of segments and queries
    n = random.randint(1, n_max)
    q = random.randint(1, q_max)
    
    # Generate segment lengths (each <= a_max)
    a = [random.randint(1, a_max) for _ in range(n)]
    
    # Generate queries (each between 0 and total length of the dance sequence - 1)
    total_length = sum(a)
    queries = [random.randint(0, total_length - 1) for _ in range(q)]
    
    # Formatting the output as strings for easy file or console output
    result = []
    result.append(f"{n} {q}")
    result.append(" ".join(map(str, a)))
    result.extend(map(str, queries))
    
    # Join everything as a single string
    return " ".join(result)
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
    executable1 = './step_brute'
    executable2 = './step'
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
