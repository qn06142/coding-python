n = int(input())
a = list(int(input()) for i in range(0, n))
best = float('-inf')
bestend = 0
for i in range(0, n):
    bestend += a[i]
    if best < bestend:
        best = bestend
    if bestend < 0:
        bestend = 0
print(best)