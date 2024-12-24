import math

def gen(primes):
    lim = min(10 ** 18, math.isqrt(primes[-1] ** k))
    result = set()
    result.add(1)

    # Helper function to recursively generate numbers
    def generate(current, index):
        if current >= lim:
            return
        if current > 1:
            result.add(current)
        if index == len(primes):
            return
        power = 1
        while current * (primes[index] ** power) < lim:
            generate(current * (primes[index] ** power), index + 1)
            power += 1
        # Skip the current prime and proceed with the next one
        generate(current, index + 1)

    # Start generating numbers
    generate(1, 0)
    return sorted(result)

def count_less_equal(arr, value):
    # Count the number of elements in arr that are <= value
    count = 0
    for x in arr:
        if x > value:
            break
        count += 1
    return count

def solve(n, primes, k):
    a = gen(primes[:len(primes) // 2])
    b = gen(primes[len(primes) // 2:])
    
    # Perform binary search over the possible product values
    low, high = 1, 10**18
    while low < high:
        mid = (low + high) // 2
        count = 0
        
        # Count pairs (x, y) such that x * y <= mid
        for x in a:
            if x > mid:
                break
            count += count_less_equal(b, mid // x)
        
        if count >= k:
            high = mid
        else:
            low = mid + 1
    
    return low

# Input parsing
n = int(input())
primes = sorted([int(i) for i in input().split()])
k = int(input())

# Solve and output the result
print(solve(n, primes, k))
