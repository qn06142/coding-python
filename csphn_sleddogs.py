import itertools
import math

def min_dogs_required_bruteforce(n, k, a, b):
    min_dogs = float('inf')

    for perm in itertools.permutations(a):
        total_dogs = 0

        for i in range(n):
            total_dogs += math.ceil((perm[i] + b[i]) / k)

        min_dogs = min(min_dogs, total_dogs)

    return min_dogs

n,k=list(map(int, input().strip().split()))
a = list(map(int, input().strip().split()))
b = list(map(int, input().strip().split()))

result = min_dogs_required_bruteforce(n, k, a, b)

print(result)
