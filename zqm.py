hashmap = dict()

n = int(input())
a = [int(i) for i in input().split()]

ans = 0
max_ = 0
bs = tuple(int(i) for i in input().split())
for i in range(0, n):
    b = bs[i]
    if a[i] == 0 and b == 0:
        anms += 1
    if a[i] != 0:
        try:
            hashmap[b / a[i]] += 1
        except:
            hashmap[b / a[i]] = 1
        max_ = max(max_, hashmap[b / a[i]])
print(max_ + ans)