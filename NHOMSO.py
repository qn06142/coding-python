import sys

def nhap():
    n = int(input())
    d = [0] * 1000005
    mi = 1000000
    ma = -1000000
    for i in range(1, n + 1):
        x = int(input())
        d[x] += 1
        if x < mi:
            mi = x
        if x > ma:
            ma = x
    return d, mi, ma

def giai(d, mi, ma):
    res = 0
    for i in range(mi, ma // 2 + 1):
        if d[i] > 0 and d[i * 2] > 0:
            k = min(d[i], d[i * 2])
            res += k
            d[i * 2] -= k
    print(res)

def main():
    t = int(input())
    for _ in range(t):
        d, mi, ma = nhap()
        giai(d, mi, ma)

if __name__ == "__main__":
    main()

