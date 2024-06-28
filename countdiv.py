def sieve_of_eratosthenes(max_num):
    is_prime = [True] * (max_num + 1)
    p = 2
    while (p * p <= max_num):
        if (is_prime[p] == True):
            for i in range(p * p, max_num + 1, p):
                is_prime[i] = False
        p += 1
    primes = []
    for p in range(2, max_num + 1):
        if is_prime[p]:
            primes.append(p)
    return primes

def count_numbers_with_least_prime(primes, max_num):
    least_prime_factor = [0] * (max_num + 1)
    for p in primes:
        for multiple in range(p, max_num + 1, p):
            if least_prime_factor[multiple] == 0:
                least_prime_factor[multiple] = p

    count_dict = {p: 0 for p in primes}
    for num in range(2, max_num + 1):
        if least_prime_factor[num] in count_dict:
            count_dict[least_prime_factor[num]] += 1

    return count_dict

def solve(primes, count_dict, x):
    if x in count_dict:
        return count_dict[x]
    else:
        return 0

# Main function to process input and produce output
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    xs = list(map(int, data[1:n+1]))

    max_num = 10 ** 5
    primes = sieve_of_eratosthenes(max_num)
    count_dict = count_numbers_with_least_prime(primes, max_num)

    results = []
    for x in xs:
        results.append(solve(primes, count_dict, x))
    
    for result in results:
        print(result)

# Uncomment the following line if running the script directly
main()
