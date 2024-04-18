N = 1001
n, m = 0, 0
a = [['']*N for _ in range(N)]
f = [[0]*N for _ in range(N)]

def InP():
    global n, m, a
    n, m = map(int, input().split())
    for i in range(1, n+1):
        a[i] = list(input())

def Dp():
    global n, m, a, f
    f[0][1] = 1
    for i in range(1, n+1):
        for j in range(1, m+1):
            if a[i-1][j-1] == '#':
                continue
            f[i][j] = (f[i - 1][j] + f[i][j - 1]) % 1000000007
    print(f[n][m])

def main():
    InP()
    Dp()

if __name__ == "__main__":
    main()
