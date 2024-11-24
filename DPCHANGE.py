MAXN = 10**6 + 5
n = 0
a = [0]*MAXN
f = [[0]*3 for _ in range(MAXN)]

def InP():
    global n, a
    n = int(input())
    a = list(map(int, input().split()))

def Dp():
    global n, a, f
    for i in range(1, n+1):
        for j in range(2, 0, -1):
            if j == a[i-1] and a[i-1] == 2:
                f[i][j] = min(f[i - 1][j], f[i - 1][j - 1])
            elif j == a[i-1]:
                f[i][j] = f[i - 1][j]
            elif j != a[i-1] and j == 2:
                f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]) + 1
            else:
                f[i][j] = f[i - 1][j] + 1
    print(min(f[n][1], f[n][2]))

def main():
    InP()
    Dp()

if __name__ == "__main__":
    main()
