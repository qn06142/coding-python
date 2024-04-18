N = 10**6 + 5
R = 10**9 + 7
f = [0] * N

def Inp():
    global n
    n = 10**6

def Dp():
    f[0] = f[1] = 1
    for i in range(2, n + 1):
        f[i] = (f[i - 1] + f[i - 2]) % R

Inp()
Dp()

t = int(input())
for _ in range(t):
    n = int(input())
    print(f[n])
