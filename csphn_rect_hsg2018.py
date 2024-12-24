def count_zero_rectangles(m, n, A):
    # Bước 1: Tính mảng zero_count
    zero_count = [[0] * n for _ in range(m)]
    for i in range(m):
        for j in range(n):
            if A[i][j] == 0:
                zero_count[i][j] = zero_count[i][j-1] + 1 if j > 0 else 1
            else:
                zero_count[i][j] = 0

    # Bước 2: Đếm số hình chữ nhật con
    total_rectangles = 0
    for a in range(1, m+1):  # Chiều cao hình chữ nhật
        for b in range(1, n+1):  # Chiều rộng hình chữ nhật
            for i in range(a-1, m):  # Hình chữ nhật kết thúc ở hàng i
                for j in range(b-1, n):  # Hình chữ nhật kết thúc ở cột j
                    valid = True
                    for k in range(a):
                        if zero_count[i-k][j] < b:
                            valid = False
                            break
                    if valid:
                        total_rectangles += 1

    return total_rectangles

m, n = 2, 2
A = [
    [0, 0],
    [0, 1]
]
print(count_zero_rectangles(m, n, A))  # Kết quả