def generate_test_case():
    # Random values for n and q within the given constraints
    n = random.randint(1, 10)
    q = 3
    
    # Random initial array a of n integers (values between -10^6 and 10^6)
    a = [random.randint(-10**1, 10**1) for _ in range(n)]
    
    # List of possible operations
    operations = ['A', 'D', 'L', 'R', 'Q']
    
    # Generate q random operations
    ops = []
    current_pointer = n  # Pointer starts at the end of the array
    
    for _ in range(q):
        op = random.choice(operations)
        
        if op == 'A':
            # Insert operation: Generate a random number to insert
            x = random.randint(-10**1, 10**1)
            ops.append(f'A {x}')
        elif op == 'D':
            # Delete operation: Only possible if the pointer is not at the beginning
            if current_pointer > 0:
                ops.append('D')
                current_pointer -= 1
        elif op == 'L':
            # Move left operation: Only possible if the pointer is not at the start
            if current_pointer > 0:
                ops.append('L')
                current_pointer -= 1
        elif op == 'R':
            # Move right operation: Only possible if the pointer is not at the end
            if current_pointer < len(a):
                ops.append('R')
                current_pointer += 1
        elif op == 'Q':
            # Query operation: Record the query
            ops.append('Q')

    # Format the test case as a string to be piped to stdin
    result = f'{n} {q}\n'
    result += ' '.join(map(str, a)) + '\n'
    result += '\n'.join(ops) + '\n'
    
    return result
import subprocess
import random
import string
import multiprocessing
import shutil
import os
import stat
import sys
import threading

stop_flag = threading.Event()  # Flag to indicate stopping the program
def run_program(executable, input_data):
    process = subprocess.Popen([executable], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate(input=input_data.encode())
    return stdout.decode().strip()

def run_test_case(executable1, executable2, test_case):
    output1 = run_program(executable1, test_case)
    output2 = run_program(executable2, test_case)
    if output1 != output2:
        sys.stdout.write(f"Test case: {test_case}\n")
        return False
    return True

def worker(executable1, executable2, tests):
    for _ in range(tests):
        if stop_flag.is_set():  # Check if stop flag is set
            return False
        test_case = generate_test_case()
        if not run_test_case(executable1, executable2, test_case):
            return False
    return True

def listen_for_quit():
    global stop_flag
    sys.stdout.write("\nPress 'q' to quit.\n")
    while not stop_flag.is_set():
        char = sys.stdin.read(1)  # Read one character
        if char.lower() == 'q':
            stop_flag.set()
            sys.stdout.write("\nQuitting...\n")

def main():
    executable1 = './editor1'
    executable2 = './editor'

    from multiprocessing import cpu_count
    n_cores = cpu_count()
    sys.stdout.write(f'Number of Logical CPU cores: {n_cores}\n')

    tests_per_worker = 10  
    num_workers = n_cores + 10    
    pool = multiprocessing.Pool(processes=num_workers)

    listener_thread = threading.Thread(target=listen_for_quit, daemon=True)  # Daemon thread for listening
    listener_thread.start()
    def cleanup():
        pool.terminate()  # Stop all workers
        pool.join()       # Ensure cleanup
        sys.stdout.write("All workers terminated. Exiting...\n")
        sys.exit(0)
    try:
        test = 0
        while not stop_flag.is_set():
            test += 1
            sys.stdout.write(f"number: {test * num_workers} \r")
            sys.stdout.flush()
            for i in pool.starmap(worker, [(executable1, executable2, tests_per_worker) for _ in range(num_workers)]):
                if not i or stop_flag.is_set():
                    cleanup()
    finally:
        cleanup()

if __name__ == "__main__":
    main()
