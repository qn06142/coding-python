MAXN = 10**6 + 1
n, m, k = 0, 0, 0
a = [0]*101
f = [[0]*10001 for _ in range(101)]

def InP():
    global n, m, k, a
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))

def Dp():
    global n, m, k, a, f
    for i in range(n+1):
        f[i][0] = 1
    for i in range(1, n+1):
        for j in range(1, m+1):
            f[i][j] = f[i - 1][j]
            if j >= a[i-1]:
                f[i][j] += f[i - 1][j - a[i-1]]
    if f[n][m] >= k:
        print("ENOUGH")
    else:
        print(f[n][m])

def main():
    InP()
    Dp()

if __name__ == "__main__":
    main()
