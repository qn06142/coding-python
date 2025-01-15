
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


def generate_test_case(max_len=4, max_k=2, seed=None):
    """
    Generate a random test case for the DP problem.
    
    Args:
    - max_len (int): Maximum length of the strings `s` and `t`.
    - max_k (int): Maximum value of `k`.
    - seed (int or None): Random seed for reproducibility.
    
    Returns:
    - dict: A dictionary containing `n`, `m`, `k`, `s`, and `t`.
    """
    if seed is not None:
        random.seed(seed)
    
    # Random lengths for strings `s` and `t`
    n = random.randint(1, max_len)
    m = random.randint(1, max_len)
    
    # Random k within a reasonable range
    k = random.randint(1, min(max_k, min(n, m)))
    
    # Random strings `s` and `t`
    s = ''.join(random.choices(string.ascii_lowercase, k=n))
    t = ''.join(random.choices(string.ascii_lowercase, k=m))
    
    return f"{n} {m} {k}\n{s}\n{t}"
def run_program(executable, input_data):
    process = subprocess.Popen([executable] if type(executable) == str else executable, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
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
    executable1 = './seglcs1'
    executable2 = './seglcs'
    
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
