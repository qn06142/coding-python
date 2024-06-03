def max_k(x, y, n):
    # Tìm số nguyên lớn nhất mà nhỏ hơn hoặc bằng n và chia hết cho x
    max_divisible = (n // x) * x
    # Trừ đi một số hợp lệ để có được kết quả mod x bằng y
    if max_divisible + y <= n:
        return max_divisible + y
    else:
        return max_divisible - (x - y)

x, y, n = (int(i) for i in input().split())
print(max_k(x, y, n))
