MAXN = 10**3 + 1
R = 10**9 + 7
n, S = 0, 0
a = [0]*MAXN
f = [0]*MAXN

def InP():
    global n, S, a
    n, S = map(int, input().split())
    a = list(map(int, input().split()))

def Dp():
    global n, S, a, f
    f[0] = 1
    for i in range(1, n+1):
        for j in range(S, a[i-1]-1, -1):
            if f[j - a[i-1]]:
                f[j] = (f[j] + f[j - a[i-1]]) % R
    print(f[S])

def main():
    InP()
    Dp()

if __name__ == "__main__":
    main()
