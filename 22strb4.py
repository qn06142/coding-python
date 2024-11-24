def max_lonely_buildings(heights, n):
    prefix = [0] * (n + 1)
    for i in range(n):
        prefix[i + 1] = prefix[i] + heights[i]
    max_lonely = 0
    for i in range(n):
        for j in range(i + 1, n + 1):
            total_height = prefix[j] - prefix[i]
            days = total_height // (j - i)
            lonelies = sum(1 for k in range(i, j) if heights[k] > days)
            max_lonely = max(max_lonely, lonelies)
    return max_lonely
n = int(input())
heights = [int(i) for i in input().split()]
print(max_lonely_buildings(heights, n))
