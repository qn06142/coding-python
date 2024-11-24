MAXN = 101
R = 10**9 + 7
n, w = 0, 0
W = [0]*MAXN
V = [0]*MAXN
f = [[0]*100001 for _ in range(MAXN)]

def InP():
    global n, w, W, V
    n, w = map(int, input().split())
    for i in range(1, n+1):
        W[i], V[i] = map(int, input().split())

def Dp():
    global n, w, W, V, f
    res = 0
    for i in range(1, int(1e5)+1):
        f[0][i] = 1e18
    for i in range(1, n+1):
        for j in range(1, 100000+1):
            if j >= V[i]:
                f[i][j] = min(f[i - 1][j], f[i - 1][j - V[i]] + W[i])
            else:
                f[i][j] = f[i - 1][j]
    for i in range(100000+1):
        if f[n][i] <= w:
            res = max(res, i)
    print(res)

def main():
    InP()
    Dp()

if __name__ == "__main__":
    main()
