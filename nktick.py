def min(x, y):
    return x if x < y else y

def init():
    global t, r, n
    n = int(input())
    t = [0] + [int(i) for i in input().split()]
    r = [0] + [int(i) for i in input().split()]

def optimize():
    global f, g
    f = [0] * (n + 1)
    g = [0] * (n + 1)
    f[1] = t[1]
    g[1] = 1 << 20
    f[2] = t[1] + t[2]
    g[2] = r[1]
    
    for i in range(3, n + 1):
        f[i] = min(f[i - 1], g[i - 1]) + t[i]
        g[i] = min(f[i - 2], g[i - 2]) + r[i - 1]
    
    print(min(f[n], g[n]))

if __name__ == "__main__":
    init()
    optimize()
