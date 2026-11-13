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

def generate_test_case(n, m):
    """
    Sinh đơn đồ thị vô hướng liên thông gồm n đỉnh, m cạnh.
    Điều kiện hợp lệ: n - 1 <= m <= n * (n - 1) // 2
    """
    max_edges = n * (n - 1) // 2
    if m < n - 1 or m > max_edges:
        raise ValueError(f"m phải thỏa mãn {n - 1} <= m <= {max_edges}")

    edges = set()

    # 1. Tạo cây khung n - 1 cạnh để đảm bảo liên thông
    nodes = list(range(1, n + 1))
    random.shuffle(nodes)  # Xáo trộn nhãn đỉnh
    
    for i in range(1, n):
        # Nối node hiện tại với một node ngẫu nhiên đã được đưa vào cây
        u = nodes[i]
        v = nodes[random.randint(0, i - 1)]
        edge = (min(u, v), max(u, v))
        edges.add(edge)

    # 2. Bổ sung thêm các cạnh còn lại cho đủ m
    remaining_needed = m - len(edges)
    
    # Nếu số cạnh cần thêm ít, random thử lại (rejection sampling)
    # Nếu m gần cực đại (đồ thị dày), liệt kê tất cả các cạnh khả dĩ để sample
    if remaining_needed > 0:
        if m < max_edges // 2:
            while len(edges) < m:
                u = random.randint(1, n)
                v = random.randint(1, n)
                if u != v:
                    edge = (min(u, v), max(u, v))
                    edges.add(edge)
        else:
            all_possible = []
            for u in range(1, n + 1):
                for v in range(u + 1, n + 1):
                    if (u, v) not in edges:
                        all_possible.append((u, v))
            
            chosen_edges = random.sample(all_possible, remaining_needed)
            edges.update(chosen_edges)

    # 3. Format output
    edge_list = list(edges)
    random.shuffle(edge_list)  # Xáo trộn thứ tự xuất hiện các cạnh

    lines = [f"{n} {m}"]
    for u, v in edge_list:
        # Ngẫu nhiên đảo vị trí u, v khi in ra
        if random.random() < 0.5:
            lines.append(f"{u} {v}")
        else:
            lines.append(f"{v} {u}")

    return "\n".join(lines)
def run_program(executable, input_data, tle = True):
    process = subprocess.Popen([executable] if type(executable) == str else executable, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    try:
        stdout, stderr = process.communicate(input=input_data.encode())
        if tle:
            if process.poll() is None:
                process.communicate(timeout=10)
        return stdout.decode().strip()
    except subprocess.TimeoutExpired:
        process.kill()
        return random.randint()


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
        test_case = generate_test_case(7, 7)  # Ví dụ: đồ thị với 5 đỉnh và 7 cạnh
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
    executable1 = './thing'
    executable2 = './thing1'
    
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
