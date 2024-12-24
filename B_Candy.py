import heapq

def max_happiness(N, M, A, B):
    # Sắp xếp giới hạn độ ngọt của học sinh và danh sách độ ngọt của kẹo
    A.sort()
    B.sort()

    # Mảng kết quả lưu độ hạnh phúc tối đa cho mỗi số lượng kẹo từ 1 đến M
    result = [0] * M

    # Hàng đợi ưu tiên (min-heap) để lưu số kẹo mà mỗi học sinh nhận được
    heap = []
    student_idx = 0  # Con trỏ duyệt qua danh sách học sinh

    for i in range(1, M + 1):  # Xét từng số lượng kẹo từ 1 đến M
        # Phân phát kẹo thứ `i` (lưu ý: B[i-1] là viên kẹo thứ i trong danh sách đã sắp tăng dần)
        while student_idx < N and A[student_idx] <= B[i - 1]:
            # Khi giới hạn độ ngọt của học sinh <= độ ngọt của viên kẹo hiện tại, thêm học sinh vào heap
            heapq.heappush(heap, 0)  # Ban đầu mỗi học sinh nhận 0 kẹo
            student_idx += 1

        if heap:
            # Nếu có học sinh trong heap, phân phát kẹo cho học sinh nhận ít kẹo nhất
            candies_received = heapq.heappop(heap) + 1
            heapq.heappush(heap, candies_received)

        # Độ hạnh phúc là số kẹo mà học sinh nhận được ít nhất
        result[i - 1] = heap[0] if heap else 0

    return result

# Đọc input
N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# Tính độ hạnh phúc
result = max_happiness(N, M, A, B)

# In kết quả
print(" ".join(map(str, result)))