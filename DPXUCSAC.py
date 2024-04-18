MAXN = 10**3 + 1
R = 10**9 + 7
n, S = 0, 0
a = [0]*MAXN
f = [[0]*MAXN for _ in range(11)]

def InP():
    global n, S, a
    n = int(input())
    a = list(map(int, input().split()))
    S = sum(a)

def Dp():
    global n, S, a, f
    f[0][0] = 1
    for i in range(1, n+1):
        for k in range(a[i-1], 0, -1):
            for j in range(S, k-1, -1):
                if f[i - 1][j - k]:
                    f[i][j] += f[i - 1][j - k]
    res = 0
    index = 0
    for i in range(1, S+1):
        if res < f[n][i]:
            res = f[n][i]
            index = i
    print(index)

def main():
    InP()
    Dp()

if __name__ == "__main__":
    main()
