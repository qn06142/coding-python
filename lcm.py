def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

l, r = (int(i) for i in input().split())
mod = 10**9 + 7

result = 1
for i in range(l, r+1):
    result = (result * i // gcd(result, i)) % mod

print(result)
