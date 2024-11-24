import math
import sys
input = sys.stdin.read

def mo_algorithm(n, t, a, queries):
    BLOCK_SIZE = int(math.sqrt(n))

    def add(x):
        nonlocal current_strength
        count[x] += 1
        current_strength += count[x] * count[x] * x - (count[x] - 1) * (count[x] - 1) * x

    def remove(x):
        nonlocal current_strength
        current_strength += (count[x] - 1) * (count[x] - 1) * x - count[x] * count[x] * x
        count[x] -= 1

    queries = sorted(queries, key=lambda q: (q[0] // BLOCK_SIZE, q[1]))

    currentL, currentR = 0, -1
    current_strength = 0
    count = [0] * (10**6 + 1)
    results = [0] * t

    for i, (l, r, idx) in enumerate(queries):
        while currentR < r:
            currentR += 1
            add(a[currentR])
        while currentR > r:
            remove(a[currentR])
            currentR -= 1
        while currentL < l:
            remove(a[currentL])
            currentL += 1
        while currentL > l:
            currentL -= 1
            add(a[currentL])

        results[idx] = current_strength

    return results

data = input().split()
idx = 0
n = int(data[idx])
idx += 1
t = int(data[idx])
idx += 1

a = [0] * n
for i in range(n):
    a[i] = int(data[idx])
    idx += 1

queries = []
for i in range(t):
    l = int(data[idx]) - 1
    idx += 1
    r = int(data[idx]) - 1
    idx += 1
    queries.append((l, r, i))

results = mo_algorithm(n, t, a, queries)

sys.stdout.write('\n'.join(map(str, results)) + '\n')
