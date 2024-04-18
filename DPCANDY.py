MAXN = 10**4 + 1
R = 10**9 + 7
n, S = 0, 0
a = [0]*101
f = [0]*MAXN

def InP():
    global n, S, a
    n = int(input())
    a = list(map(int, input().split()))
    S = sum(a)

def Dp():
    global n, S, a, f
    f[0] = 1
    for i in range(1, n+1):
        for j in range(S//2, a[i-1]-1, -1):
            if f[j - a[i-1]]:
                f[j] = 1
    for i in range(S//2, 0, -1):
        if f[i]:
            print(S - 2*i)
            break

def main():
    InP()
    Dp()

if __name__ == "__main__":
    main()
