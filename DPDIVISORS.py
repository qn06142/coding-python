MAXN = 10**6 + 1
n = 0
a = [0]*MAXN
f = [0]*MAXN
Divisor = [[] for _ in range(MAXN)]

def InP():
    global n, a
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()

def cnt_Divisor():
    global Divisor
    for i in range(1, int(1e6)+1):4
        for j in range(i+i, int(1e6)+1, i):
            Divisor[j].append(i)

def Dp():
    global n, a, f, Divisor
    res = 1
    for i in range(1, n+1):
        f[a[i-1]] += 1
        for j in Divisor[a[i-1]]:
            f[a[i-1]] = max(f[a[i-1]], f[j] + 1)
        res = max(res, f[a[i-1]])
    print(n - res)

def main():
    InP()
    cnt_Divisor()
    Dp()

if __name__ == "__main__":
    main()
