import math
for _ in range(int(input())):
    n, k = map(int, input().split())
    if n > k:
        print("0 1")
        continue
    numer = (k - n + 1) * pow(k + 1, n - 1)
    ddenom = pow(k, n)

    g = math.gcd(numer, ddenom)
    numer //= g
    ddenom //= g
    print(numer, ddenom)
