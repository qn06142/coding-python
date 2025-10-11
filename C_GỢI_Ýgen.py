def generate_test_case1(n, s, q):
    """
    Generate the test case string for the pyramid problem.

    Args:
        n (int): Number of rows in the pyramid.
        s (str): The string to be repeated in the pyramid.
        q (int): Number of queries.

    Returns:
        str: The test case as a single string.
    """
    test_case = [f"{n}", f"{s}", f"{q}"]
    
    for _ in range(q):
        query_type = random.choice([1, 2])
        if query_type == 1:
            # Query type 1: "1 i x", where i is the row, x is a random character in s
            i = random.randint(1, n)
            x = random.choice(s)
            test_case.append(f"1 {i} {x}")
        else:
            # Query type 2: "2 i j", where i is the row and j is a column in that row
            i = random.randint(1, n)
            j = random.randint(1, i)
            test_case.append(f"2 {i} {j}")
    
    return "\n".join(test_case)
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

def generate_test_case(n=20, q=8, max_word_len=10, alphabet=string.ascii_lowercase):
    """
    Returns a test case string with:
      - n random words (lowercase, length 1..max_word_len),
      - q random prefix‐queries.
    Format:
        n
        word1
        word2
        ...
        wordn
        q
        pref1
        pref2
        ...
        prefq
    """
    words = []
    for _ in range(n):
        L = random.randint(1, max_word_len)
        w = ''.join(random.choice(alphabet) for _ in range(L))
        words.append(w)
    prefixes = []
    for _ in range(q):
        # pick some existing word at random and take a random prefix of it,
        # or generate a totally random prefix
        if random.random() < 0.7 and words:
            w = random.choice(words)
            cut = random.randint(1, len(w))
            prefixes.append(w[:cut])
        else:
            L = random.randint(1, max_word_len)
            prefixes.append(''.join(random.choice(alphabet) for _ in range(L)))
    # assemble as one big string
    parts = [str(n)] + words + [str(q)] + prefixes
    return '\n'.join(parts)
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
    executable1 = './C_GỢI_Ý'
    executable2 = './C_GỢI_Ý1'
    
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
