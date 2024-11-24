n , h = tuple(int(i) for i in input().split())
def sieve_of_eratosthenes(n):
    primes = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (primes[p] == True):
            for i in range(p * p, n+1, p):
                primes[i] = False
        p += 1
    prime_numbers = [p for p in range(2, n) if primes[p]]
    return prime_numbers
ans = []
for i in sieve_of_eratosthenes(n):
	if sum(tuple(int(j) for j in list(str(i)))) == h:
		ans.append(i)
print(len(ans))
for i in ans:
	print(i)