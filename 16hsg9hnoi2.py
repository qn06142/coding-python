from itertools import accumulate
n = int(input())
print(*accumulate([int(i) for i in input().split()], max))