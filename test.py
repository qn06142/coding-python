import itertools
a = [1, 3, 5, 9] * 4
ans = 0
for i in itertools.combinations(a, 4):
    n = int(''.join(str(j) for j in i))
    if n % 3 == 0:
        ans += 1
print(ans)