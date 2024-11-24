def lineup(n, h):
    stack = []
    res = [-1]*n
    for i in range(n-1, -1, -1):
        while stack and h[stack[-1]] < h[i]:
            res[stack.pop()] = i
        stack.append(i)
    return res

# Đọc dữ liệu từ giao diện dòng lệnh
n = int(input())
h = list(map(int, input().split()))

# Tính toán kết quả
res = lineup(n, h)

# In kết quả ra giao diện dòng lệnh
print(' '.join(map(str, res)))
