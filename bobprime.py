def sieve_of_eratosthenes(n):

    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for p in range(2, int(n**0.5) + 1):
        if is_prime[p]:
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
    for num in range(2, n + 1):
        if is_prime[num]:
            yield num
def find_cubes(n):
    cubes = []
    for i in sieve_of_eratosthenes(int(n**1/3)):
        cubes.append(i ** 3)
    #print(*cubes)
    return cubes

def count_solutions(n):
    cubes = find_cubes(n)
    count = 0
    for i in range(len(cubes)):
        for j in range(i, len(cubes)):
            s = cubes[i] * cubes[j]
            if s <= n and cubes[i] != cubes[j]:
                #print(s, cubes[i], cubes[j])
                count += 1
    return count

n = int(input())
result = count_solutions(n)
print(result)
