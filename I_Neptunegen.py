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

def generate_test_case(n=5, q=500, charset='abc', max_len=200):
    def rand_str(len=max_len):
        return ''.join(random.choices(charset, k=random.randint(1, len)))
    
    initial = [rand_str() for _ in range(n)]
    current = initial[:]
    ops = []

    for _ in range(q):
        op = random.choice(['i', 'e', 'q'])
        if op == 'i':
            s = rand_str()
            current.append(s)
            ops.append(f"i {s}")
        elif op == 'e' and current:
            s = random.choice(current)
            current.remove(s)
            ops.append(f"e {s}")
        else:  # query
            s = rand_str(10)
            ops.append(f"q {s}")

    test = [str(n)] + initial + [str(q)] + ops
    return '\n'.join(test)

def run_program(executable, input_data):
    process = subprocess.Popen([executable] if type(executable) == str else executable, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate(input=input_data.encode())
    return stdout.decode().strip()


def run_test_case(executable1, executable2, test_case):
    output1 = run_program(executable1, test_case)
    output2 = run_program(executable2, test_case)
    if output1 != output2:
        sys.stdout.write(f"Test case: {test_case}\n")
        print()
        print(output1)
        print()
        print(output2)
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
    executable1 = './I_Neptune1'
    executable2 = './I_Neptune'
    
    from multiprocessing import cpu_count
    n_cores = cpu_count()
    sys.stdout.write(f'Number of Logical CPU cores: {n_cores}\n')

    tests_per_worker = 10  
    num_workers = n_cores 
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
