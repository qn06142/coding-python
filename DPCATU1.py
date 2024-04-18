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
    for i in range(1, n+1):
        for j in range(1, w+1):
            f[i][j] = f[i - 1][j]
            if j >= W[i]:
                f[i][j] = max(f[i][j], f[i - 1][j - W[i]] + V[i])
    print(f[n][w])

def main():
    InP()
    Dp()

if __name__ == "__main__":
    main()
