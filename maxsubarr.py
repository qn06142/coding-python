n, m = map(int, input().split())
a = list(map(int, input().split()))

# Calculate prefix sum directly
pref = [0] * (n + 1)
for i in range(n):
    pref[i + 1] = pref[i] + a[i]

def check(k):
    for i in range(n - k + 1):
        if pref[i + k+1] - pref[i + 1] > m:
            return False
    return True

l, r = n, 1
while l <= r:
    mid = (l + r) // 2
    if check(mid):
        l = mid
    else:
        r = mid + 1

result = l
print(result)
