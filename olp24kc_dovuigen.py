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

import random
import string

def generate_test_case(n_min=2, n_max=100, seed=None):
    """
    Generate a test case for the problem.

    Parameters:
    - n_min: Minimum length of the output string z (default 2).
    - n_max: Maximum length of the output string z (default 100).
    - seed: Random seed for reproducibility (default None).

    Returns:
    - A string containing the test case in the required input format.
    """
    if seed is not None:
        random.seed(seed)
    
    # Generate a random length for the original string `s`
    len_s = random.randint(n_min // 2, n_max // 2)
    
    # Generate the original string `s`
    s = ''.join(random.choices(string.ascii_uppercase, k=len_s))
    
    # Create the doubled string `t`
    t = s + s
    
    # Insert an extra character at a random position in `t`
    extra_char = random.choice(string.ascii_uppercase)
    pos = random.randint(0, len(t))
    z = t[:pos] + extra_char + t[pos:]
    
    # Prepare the test case as a string
    test_case = f"{len(z)}\n{z}"
    
    return test_case

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
    executable1 = './olp24kc_dovui1'
    executable2 = './olp24kc_dovui'

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
