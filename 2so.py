input()
a = sorted(int(i) for i in input().split())
import itertools
print(max(i[0] * i[1] for i in itertools.chain(itertools.product((a[0], ), a[1:]), itertools.product((a[-1],), a[:-1]))))