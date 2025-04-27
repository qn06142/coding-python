import random
import concurrent.futures

def isprime(n, k=5):
    # Basic checks
    if n <= 1:
        return False, -1
    if n <= 3:
        return True, 0
    if n % 2 == 0:
        return False, -1
    # Fermat-style test for k iterations
    for i in range(k):
        a = random.randint(2, n * n)
        if pow(a, n - 1, n) != 1:
            return False, i  # Composite
    return True, k  # Probably prime

def generate_candidate():
    # Generate a 1024-byte random number
    # Note: 'big' specifies the byte order
    large = random.randbytes(64)
    return int.from_bytes(large, 'big')

def test_candidate():
    candidate = generate_candidate()
    result, iterations = isprime(candidate, k=5000)
    return candidate, result, iterations

def main():
    tries = 0
    prime_candidate = None
    # Using a pool of processes to parallelize candidate testing.
    with concurrent.futures.ProcessPoolExecutor() as executor:
        # Start with a batch of tasks; adjust the number of workers as needed.
        futures = {executor.submit(test_candidate) for _ in range(32)}
        while futures:
            # Wait until at least one future completes.
            done, futures = concurrent.futures.wait(futures, return_when=concurrent.futures.FIRST_COMPLETED)
            for fut in done:
                tries += 1
                candidate, is_prime, iterations = fut.result()
                print("                                        \r", end = '')
                print(f"Try {tries}, iterations: {iterations}\r", end = '')
                if is_prime:
                    print("Prime candidate found!")
                    prime_candidate = candidate
                    # Cancel any pending tasks and shut down the pool.
                    executor.shutdown(wait=False, cancel_futures=True)
                    return prime_candidate
                else:
                    # Resubmit a new candidate if this one is composite.
                    futures.add(executor.submit(test_candidate))
    return prime_candidate

if __name__ == '__main__':
    result = main()
    print("Prime candidate:", result)
