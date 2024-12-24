def fermat(n):
    upper_bound = 40 if n >= 40 else n - 1
    return all(pow(a, n - 1, n) == 1
               for a in range(2, upper_bound + 1))
# ^ we could use sieve but im lazy
import math
for _ in range(0, int(input())):
    n = int(input())
    if math.isqrt(n) ** 2 == n and fermat(math.isqrt(n)):
        print("YES")
    else:
        print("NO")