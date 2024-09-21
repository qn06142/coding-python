def sieve(n):
    isprime = [True] * 10000
    isprime[0] = isprime[1] = False
    for p in range(2, int(n**0.5) + 1):
        if isprime[p]:
            for i in range(p * p, n + 1, p):
                isprime[i] = False
    return isprime

def main():
    dp = [[0] * 2005 for _ in range(2005)]
    prime = [True] * 1005

    isprime = sieve(1005)

    for i in range(1, 10):
        dp[1][i] = 1

    for i in range(2, 300):
        for j in range(1000):
            for k in range(10):
                dp[i][j + k] += dp[i - 1][j]

    dp[0][1] = 1
    ans = 0

    q = int(input())
    for _ in range(q):
        l, r = map(int, input().split())
        ans = 0
        for i in range(l, r + 1):
            for j in range(2, 901):
                if isprime[j]:
                    ans += dp[i][j]
        print(ans)

if __name__ == "__main__":
    main()

