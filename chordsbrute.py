from itertools import combinations

# Hàm kiểm tra xem hai dây cung có cắt nhau không
def is_intersect(arc1, arc2):
    a1, b1 = arc1
    a2, b2 = arc2
    # Điều kiện cắt nhau: Một dây cung nằm giữa hai đầu mút của dây cung kia
    return (a1 < a2 < b1 < b2) or (a2 < a1 < b2 < b1)

# Hàm brute force để tìm số lượng dây cung lớn nhất mà không cắt nhau
def brute_force_arcs(n, arcs):
    max_count = 0
    
    # Duyệt qua tất cả các tập con của các dây cung
    for r in range(1, n + 1):
        for subset in combinations(arcs, r):
            # Kiểm tra xem tập con này có dây cung nào cắt nhau không
            is_valid = True
            for i in range(len(subset)):
                for j in range(i + 1, len(subset)):
                    if is_intersect(subset[i], subset[j]):
                        is_valid = False
                        break
                if not is_valid:
                    break
            # Nếu tập con hợp lệ, cập nhật số lượng dây cung
            if is_valid:
                max_count = max(max_count, len(subset))
    
    return max_count

# Đọc dữ liệu
n = int(input())  # Số lượng dây cung
arcs = []

for _ in range(n):
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a  # Sắp xếp để a luôn nhỏ hơn b
    arcs.append((a, b))

# Tìm kết quả bằng brute force
result = brute_force_arcs(n, arcs)
print(result)