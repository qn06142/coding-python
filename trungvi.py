n = int(input())
a = list(int(i) for i in input().split())
stor = dict()
for i in a:
    try:
        stor[i] += 1
    except:
        stor[i] = 1

l = 0
r = 10 ** 4 + 5
ans = -1
while l <= r:
    mid = (l + r) >> 1
    tmp = 0
    for i in stor:
        tmp += -stor[i] if i < mid else stor[i]
    
    if tmp >= 0:
        l = mid + 1
        ans = mid
    else:
        r = mid - 1
print(ans)