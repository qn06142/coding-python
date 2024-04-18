from bisect import bisect_left
def take_closest(myList, myNumber):
    pos = bisect_left(myList, myNumber)
    if pos == 0:
        return 0
    if pos == len(myList):
        return -1
    before = myList[pos - 1]
    after = myList[pos]
    if after - myNumber < myNumber - before:
        return pos
    else:
        return pos - 1
def solve(n, L, R, a):
    a.sort()
    if R <= a[0]:
        return L
    if L >= a[n-1]:
        return R
    from math import ceil
    tmpL = (abs(L - a[take_closest(a, L)]), L)
    tmpR = (abs(R - a[take_closest(a, R)]), R)
    max_distance = (float('-inf'), None)
    for i in range(1, n):
        x = ceil((a[i - 1] + a[i]) / 2)
        if x in range(L, R):
            max_distance = max(max_distance, (min(abs(x - a[i - 1]), abs(x - a[i])), x))
    
    return max(max_distance, tmpL, tmpR)[1]

n, L, R = (int(i) for i in input().split())
a = [int(i) for i in input().split()]
print(solve(n, L, R, a))
