import sys

def solve():
    """
    Hàm giải quyết bài toán tìm chuỗi lệnh di chuyển nhỏ nhất.
    """
    try:
        tx, ty = map(int, sys.stdin.readline().split())
        s = sys.stdin.readline().strip()
    except (IOError, ValueError):
        print("IMPOSSIBLE")
        return

    # Bước 1: Tính toán vị trí ban đầu và đếm số dấu '?'
    x, y = 0, 0
    q_count = 0
    for char in s:
        if char == 'R':
            x += 1
        elif char == 'L':
            x -= 1
        elif char == 'U':
            y += 1
        elif char == 'D':
            y -= 1
        elif char == '?':
            q_count += 1

    # Bước 2: Kiểm tra tính khả thi
    dx = tx - x
    dy = ty - y
    
    needed_dist = abs(dx) + abs(dy)

    if q_count < needed_dist or (q_count - needed_dist) % 2 != 0:
        print("IMPOSSIBLE")
        return

    # Bước 3: Xác định số lượng mỗi loại lệnh cần thêm
    num_d, num_l, num_r, num_u = 0, 0, 0, 0

    if dy < 0:
        num_d = -dy
    else:
        num_u = dy
    
    if dx < 0:
        num_l = -dx
    else:
        num_r = dx

    extra_pairs = (q_count - needed_dist) // 2
    # Ưu tiên cặp D-U để đảm bảo tính từ điển nhỏ nhất
    num_d += extra_pairs
    num_u += extra_pairs

    # Bước 4: Xây dựng chuỗi kết quả
    result = []
    for char in s:
        if char == '?':
            if num_d > 0:
                result.append('D')
                num_d -= 1
            elif num_l > 0:
                result.append('L')
                num_l -= 1
            elif num_r > 0:
                result.append('R')
                num_r -= 1
            else: # num_u > 0
                result.append('U')
                num_u -= 1
        else:
            result.append(char)
            
    # In kết quả
    print("".join(result))

# Chạy hàm giải
solve()