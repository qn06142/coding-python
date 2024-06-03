MOD = 10**9 + 7
MAX = 110

def calculate_comb(MAX, MOD):
    comb = [[0]*MAX for _ in range(MAX)]
    comb[0][0] = 1
    for i in range(1, MAX):
        comb[i][0] = 1
        for j in range(1, i+1):
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD
    return comb

comb = calculate_comb(MAX, MOD)

def add(x, y):
    return (x+y)%MOD

def mul(x, y):
    return (x*y)%MOD

n = int(input())
b = list(map(int,input().split()))
b.append(b[0])

dp = [[[0]*MAX for _ in range(MAX)] for _ in range(n+1)]
dp[0][0][0] = 1

for i in range(n):
    for j in range(MAX):
        for k in range(j+1):
            if dp[i][j][k]:
                for x in range(b[i]+1):
                    for y in range(min(x,k)+1):
                        dp[i+1][x][y] = add(dp[i+1][x][y], mul(dp[i][j][k], mul(comb[x][y], comb[b[i]-y+x][x])))

res = sum(sum(dp[n][j][k] for k in range(j+1)) for j in range(MAX)) % MOD
print(res)
