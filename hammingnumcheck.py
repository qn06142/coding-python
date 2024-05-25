def is_hamming(x):
    for i in [2, 3, 5]:
        while x % i == 0:
            x = x / i
    return x == 1
from sys import stdin
for line in stdin:
    print("YES" if is_hamming(int(line)) else "NO")