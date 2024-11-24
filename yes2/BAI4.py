def factors(n):
    while n > 1:
        for i in range(2, n + 1):
            if n % i == 0:
                n //= i
                yield i
                break
maxp = 5
mod = 10 ** 9 + 7
facta = [0 for i in range(0, 10 ** maxp + 5)]
factb = [0 for i in range(0, 10 ** maxp + 5)]
factfinal = [0 for i in range(0, 10 ** maxp + 5)]
n = int(input())
a = [int(i) for i in input().split()]
m = int(input())
b = [int(i) for i in input().split()]

for i in a:
    for j in factors(i):
        facta[j] += 1
for i in b:
    for j in factors(i):
        factb[j] += 1
for i in range(1, 10 ** maxp):
    factfinal[i] = min(facta[i], factb[i])
ans = 1
for i in range(1, 10 ** maxp):
    ans *= pow(i, factfinal[i], mod)
    ans %= mod
print(ans)