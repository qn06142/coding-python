
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

def generate_test_case(N_min=1, N_max=10**1, X_min=1, X_max=None):
    # Set X_max to N_max if not provided
    if X_max is None:
        X_max = N_max
    
    # Randomly select N and X
    N = random.randint(N_min, N_max)
    X = random.randint(X_min, N)
    
    # Print the generated test case
    return f"{N} {X}"
def run_program(executable, input_data):
    process = subprocess.Popen([executable] if type(executable) == str else executable, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate(input=input_data.encode())
    return stdout.decode().strip()


def run_test_case(executable1, executable2, test_case):
    output1 = run_program(executable1, test_case)
    output2 = run_program(executable2, test_case)
    if output1 != output2:
        sys.stdout.write(f"Test case: {test_case}\n")
        print(output1)
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
    executable1 = './tht2023_tq_ck_a_sox1'
    executable2 = './tht2023_tq_ck_a_sox'
    
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
    test = 0
    while not stop_flag.is_set():
        test += 1
        sys.stdout.write(f"number: {test * num_workers} \r")
        sys.stdout.flush()
        for i in pool.starmap(worker, [(executable1, executable2, tests_per_worker) for _ in range(num_workers)]):
            if not i or stop_flag.is_set():
                cleanup()

if __name__ == "__main__":
    main()
