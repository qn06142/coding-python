import subprocess
import random
import string

def generate_test_case():
    # Generate a random test case
    # For simplicity, let's assume the test case is a string of random letters
    length = random.randint(1, 10)  # Random length between 1 and 100
    return str(length) + ' ' + str(random.randint(1, 100)) + '\n' + ' '.join((str(random.randint(1, 10)) for _ in range(0, length)))

def run_program(executable, input_data):
    # Run the executable with the given input data
    process = subprocess.Popen([executable], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate(input=input_data.encode())
    return stdout.decode().strip()

def main():
    executable1 = './fc017_mowlawn.exe'
    executable2 = './fc017_mowlawn_slow.exe'
    
    while True:
        test_case = generate_test_case()
        output1 = run_program(executable1, test_case)
        output2 = run_program(executable2, test_case)
        
        if output1 != output2:
            print(f"Test case: {test_case}")
            print(f"Output of {executable1}: {output1}")
            print(f"Output of {executable2}: {output2}")
            break

if __name__ == "__main__":
    main()
