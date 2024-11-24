MAXN = 10**6 + 5
R = 10**9 + 7
f = [0] * MAXN

n = int(input())

f[0] = 1
f[1] = 2
sum = 3

for i in range(2, n + 1):
    f[i] = (2 * sum + f[i - 2]) % R
    sum += f[i]

print(f[n])
