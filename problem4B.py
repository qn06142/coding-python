n = int(input())
from fractions import Fraction as frac
fracs = [input().split() for i in range(0, n)]
ops = [None] + [input() for i in range(1, n)]
stage1 = tuple('frac(' + i[0] + ',' + i[1] + ')' for i in fracs)
stage2 = stage1[0]
for i in range(1, n):
	stage2 += ops[i] + stage1[i]
ans = (str(eval(stage2)).split(sep='/'))
if ans[1] == 1:
    print(ans[0])
else:
    print(*ans)