MAXN = 10**3 + 5
n, m = 0, 0
a = [0]*MAXN
f = [[0]*MAXN for _ in range(MAXN)]

def InP():
    global n, m, a
    n, m = map(int, input().split())
    if n > m:
        return
    a = list(map(int, input().split()))
    a = [i % m for i in a]

def Dp():
    global n, m, a, f
    if n > m:
        return True
    f[0][0] = 1
    for i in range(1, n+1):
        for j in range(m):
            f[i][j] = max(f[i - 1][j], f[i - 1][(j - a[i-1] + m) % m])
            if f[i - 1][(j - a[i-1] + m) % m] and j == 0:
                return True
    return False

def main():
    InP()
    if Dp():
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()
