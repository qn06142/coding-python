MAX_A = 300000
is_prime = [True] * (MAX_A + 1)
is_prime[0] = is_prime[1] = False
for i in range(2, int(MAX_A**0.5) + 1):
    if is_prime[i]:
        for j in range(i * i, MAX_A + 1, i):
            is_prime[j] = False

n, q = map(int, input().split())
a = list(map(int, input().split()))

diff1 = [0 for i in range(0, n + 5)]
diff2 = [0 for i in range(0, n + 5)]
for i in range(0, q):
    t, l, r, v = map(int, input().split())

    if t == 1:
        diff2[l] += v
        diff2[r + 1] -= v
    else:
        diff1[l] += v
        diff1[r + 1] -= v

for i in range(1, n + 1):
    diff1[i] += diff1[i - 1]
    diff2[i] += diff2[i - 1]
    if not is_prime[a[i - 1]]:
        print(diff1[i], end = '', flush=False)
    else:
        print(diff2[i], end = '', flush=False)
    print(flush=False, end = ' ')