MAXN = 10**3 + 1
R = 10**9 + 7
n, S = 0, 0
a = [0]*MAXN
f = [0]*MAXN

def InP():
	global n, S, a
	S, n = map(int, input().split())
	for i, itm in enumerate(input().split(), start=1):
		a[i] = int(itm)

def Dp():
    global n, S, a, f
    f[0] = 1
    for i in range(1, n+1):
        for j in range(a[i], S+1):
            if f[j - a[i]]:
                f[j] += f[j - a[i]]
    print(f[S])

def main():
    InP()
    Dp()

if __name__ == "__main__":
    main()
