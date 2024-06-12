n = int(input())
arr = [int(i) for i in input().split()]
arr.sort()
res = 1
for i in range (0, n):
    if arr[i] <= res:
        res = res + arr[i]
    else:
        break
print(res)