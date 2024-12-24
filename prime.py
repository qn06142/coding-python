def main():
    import sys
    sys.setrecursionlimit(1 << 25)
    N = 10**6 + 1
    min_prime = [0] * N
    primes = []
    for i in range(2, N):
        if min_prime[i] == 0:
            min_prime[i] = i
            primes.append(i)
        for p in primes:
            if p * i >= N:
                break
            if min_prime[i] < p:
                continue
            min_prime[p * i] = p
    prime_index = {p: idx for idx, p in enumerate(primes)}
    
    T = int(sys.stdin.readline())
    for _ in range(T):
        a, b = map(int, sys.stdin.readline().split())
        count_map = {}
        for num in range(a, b + 1):
            temp = num
            factors = set()
            while temp > 1:
                factor = min_prime[temp]
                temp //= min_prime[temp]
                factors.add(factor)
            if factors:
                indexed_factors = tuple(sorted(prime_index[f] for f in factors))
                count_map[indexed_factors] = count_map.get(indexed_factors, 0) + 1
        total = 0
        for count in count_map.values():
            if count >= 2:
                total += count * (count - 1) // 2
        print(total)

if __name__ == "__main__":
    main()