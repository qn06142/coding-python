N = 10**2 + 5
n, sum, res = 0, 0, -1e9
a = [0]*N
f = [0]*500005

def InP():
    global n, sum, a
    n = int(input())
    for i in range(1, n+1):
        a[i] = int(input())
        sum += a[i]

def Dp():
    global n, sum, a, f, res
    f[0] = 0
    for i in range(1, n+1):
        for j in range(sum//2, a[i]-1, -1):
            if f[j - a[i]] != 0 or j - a[i] == 0:
                f[j] = f[j - a[i]] + 1
                if abs(n - f[j] * 2) <= 1:
                    res = max(res, j)
    print(min(res, sum - res), max(res, sum - res))

def main():
    InP()
    Dp()

if __name__ == "__main__":
    main()
