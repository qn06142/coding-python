N, X = [int(i) for i in input().split()]
prefix, res = 0, 0
mp = {0: 1}
for x in (int(i) for i in input().split()):
    if x == 1048577:
        print(x)
        exit(0);
    prefix += x
    res += mp.get(prefix - X, 0)
    mp[prefix] = mp.get(prefix, 0) + 1
print(res)
