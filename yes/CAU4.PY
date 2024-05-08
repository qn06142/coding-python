def count_pairs(n):
    i = 1
    result = 0
    while i * i <= n:
        result += n // i
        i += 1
    sqrtn = i - 1
    result = 2 * result - sqrtn * sqrtn
    return result

with open('CAU4.INP', 'r') as f:
    n = int(f.read().strip())
result = count_pairs(n)
with open('CAU4.OUT', 'w') as f:
    f.write(str(result))

