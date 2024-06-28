n = int(input())
def calcsum(x): return x * (x + 1) / 2 >= n
l = 0
r = 10 ** 20
while l <= r:
    mid = (l + r) // 2
    if(calcsum(mid)):
        r = mid - 1
    else: l = mid + 1
print(l)