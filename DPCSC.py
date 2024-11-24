MAXN = 3005
n = 0
a = [0]*MAXN
f = [[0]*10005 for _ in range(MAXN)]

def InP():
    global n, a
    n = int(input())
    a = list(map(int, input().split()))

def Dp():
    global n, a, f
    res = 0
    for i in range(1, n+1):
        for j in range(i-1, 0, -1):
            if a[i-1] >= a[j-1]:
                f[i][a[i-1] - a[j-1]] = max(f[i][a[i-1] - a[j-1]], f[j][a[i-1] - a[j-1]] + 1)
                res = max(res, f[i][a[i-1] - a[j-1]])
    if res != 0:
        print(res + 1)
    else:
        print(0)

def main():
    InP()
    Dp()

if __name__ == "__main__":
    main()
