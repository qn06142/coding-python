n = 0
a = [0]*1005
f = [[0]*2 for _ in range(1005)]

def InP():
    global n, a
    n = int(input())
    a = list(map(int, input().split()))

def main():
    global n, a, f
    InP()
    for i in range(1, n+1):
        f[i][0] = max(f[i - 1][0], f[i - 1][1] + a[i-1])
        f[i][1] = max(f[i - 1][1], f[i - 1][0] - a[i-1])
    print(max(f[n][0], f[n][1]))

if __name__ == "__main__":
    main()
