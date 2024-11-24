MOD = 998244353

def main():
    a, b = (int(i) for i in input().split())
    ans = 0

    if a > b:
        a, b = b, a

    while a != 0:
        dist = b - a
        start = b - (dist // a) * a
        time = dist // a + 1
        s = b + start
        t = time

        if s % 2 == 0:
            s //= 2
        else:
            t //= 2

        ans += (s % MOD) * (t % MOD)
        b = start - a
        a, b = b, a

    print(ans % MOD)

if __name__ == "__main__":
    main()
