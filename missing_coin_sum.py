input()
coins = [int(i) for i in input().split()]
def findSmallest(arr, n):
    res = 1
    for i in range (0, n ):
        if arr[i] <= res:
            res = res + arr[i]
        else:
            break
    return res
print(findSmallest(sorted(coins), len(coins)))