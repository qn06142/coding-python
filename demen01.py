def max_profit(N, k, arr):
    arr.sort(key = lambda a: abs(min(a[0], a[1]) - min(2*a[0], a[1])), reverse=True)
    #print(*arr)
    profit = 0
    for i in range(N):
        if k > 0:
            profit += min(2*arr[i][0], arr[i][1])
            k -= 1
        else:
            profit += min(arr[i][0], arr[i][1])
    return profit

N, k = tuple(int(i) for i in input().split())
arr = [tuple(int(i) for i in input().split()) for i in range(0, N)]
print(max_profit(N, k, arr))