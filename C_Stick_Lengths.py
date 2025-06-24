input()
a = list(int(i) for i in input().split())
tmp = sorted(a)[len(a)//2]
med = sum(abs(i - tmp) for i in a)
print(med)