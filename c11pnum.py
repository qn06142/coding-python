def sieve_of_eratosthenes(limit):
    primes = []
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False
    for num in range(2, limit + 1):
        if is_prime[num]:
            primes.append(num)
            for multiple in range(num * num, limit + 1, num):
                is_prime[multiple] = False
    return primes

def find_largest_product(N, K, primes):
    max_product = -1
    for i in range(len(primes) - K + 1):
        product = 1
        for j in range(K):
            product *= primes[i + j]
        if product <= N:
            max_product = max(max_product, product)
        else:
            break
    return max_product

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    T = int(data[0])
    results = []
    index = 1
    primes = sieve_of_eratosthenes(10**7)  # Adjust the limit as needed
    
    for _ in range(T):
        N = int(data[index])
        K = int(data[index + 1])
        index += 2
        result = find_largest_product(N, K, primes)
        results.append(result)
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
