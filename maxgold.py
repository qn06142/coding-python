def max_gold(n, k, a):
    # Tính tổng tiền tố
    s = [[0 for _ in range(n+1)] for _ in range(n+1)]
    for i in range(1, n+1):
        for j in range(1, n+1):
            s[i][j] = a[i-1][j-1] + s[i-1][j] + s[i][j-1] - s[i-1][j-1]

    # Tìm ma trận con k x k có tổng lớn nhất
    max_gold = 0
    for i in range(k, n+1):
        for j in range(k, n+1):
            gold = s[i][j] - s[i-k][j] - s[i][j-k] + s[i-k][j-k]
            max_gold = max(max_gold, gold)

    return max_gold

# Test
n = 4
k = 3
a = [[int(i) for i in input().split()] for i in range(0, n)]
print(max_gold(n, k, a))  # Output: 45
