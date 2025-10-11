def pow2(a, b, c):
    pows = [pow(a, d, c) for d in range(10)]

    ans = 1
    for ch in b:

        d = ord(ch) - ord('0')  

        ans = pow(ans, 10, c)

        ans = (ans * pows[d]) % c

    return ans
a = int(input())
b = input()
c = int(input())
a %= c
print(pow2(a, b, c))