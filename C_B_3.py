MAX_VAL = 10**6

cnt = [0] * (MAX_VAL + 2)

N = int(input())
for c in map(int, input().split()):
    cnt[c] += 1

for i in range(1, MAX_VAL + 1):
    cnt[i] += cnt[i - 1]

ans = 0

for c in range(1, MAX_VAL + 1):
    d = cnt[c] - cnt[c - 1]
    if d == 0: 
        continue
    
    for kc in range(c, MAX_VAL + 1, c):
        k = kc // c
        contribution = (cnt[min(MAX_VAL, kc + c - 1)] - cnt[kc - 1])
        ans += k * contribution * d
    
    ans -= d * (d + 1) // 2

print(ans)
