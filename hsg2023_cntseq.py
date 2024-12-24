from sortedcontainers import SortedDict

def count_subarrays(n, a, m, queries):
    # Tìm Left[i] và Right[i]
    left = [-1] * n
    right = [n] * n
    stack = []

    # Tìm chỉ số Left
    for i in range(n):
        while stack and a[stack[-1]] <= a[i]:
            stack.pop()
        left[i] = stack[-1] if stack else -1
        stack.append(i)

    stack = []
    # Tìm chỉ số Right
    for i in range(n - 1, -1, -1):
        while stack and a[stack[-1]] < a[i]:
            stack.pop()
        right[i] = stack[-1] if stack else n
        stack.append(i)

    # Đếm số dãy con mà mỗi giá trị là lớn nhất
    count = SortedDict()

    for i in range(n):
        l = left[i] + 1  # Bắt đầu từ đâu
        r = right[i] - 1  # Kết thúc ở đâu
        num_subarrays = (i - l + 1) * (r - i + 1)  # Số dãy con mà a[i] là lớn nhất
        if a[i] in count:
            count[a[i]] += num_subarrays
        else:
            count[a[i]] = num_subarrays

    # Tính prefix sum cho SortedDict
    prefix_sum = SortedDict()
    current_sum = 0
    for key in count:
        current_sum += count[key]
        prefix_sum[key] = current_sum

    # Trả lời truy vấn
    results = []
    for L, R in queries:
        # Tìm tổng số dãy con có giá trị lớn nhất nằm trong [L, R]
        keys = prefix_sum.keys()
        if R < keys[0]:  # Nếu R nhỏ hơn giá trị nhỏ nhất trong dãy
            results.append(0)
            continue
        if L > keys[-1]:  # Nếu L lớn hơn giá trị lớn nhất trong dãy
            results.append(0)
            continue

        # Tìm giá trị cumulative sum tại R và L-1
        sum_R = prefix_sum.peekitem(prefix_sum.bisect_right(R) - 1)[1] if R >= keys[0] else 0
        sum_L_minus_1 = prefix_sum.peekitem(prefix_sum.bisect_left(L) - 1)[1] if L > keys[0] else 0
        results.append(sum_R - sum_L_minus_1)

    return results


# Đọc dữ liệu
import sys
input = sys.stdin.read
data = input().split()

n = int(data[0])
a = list(map(int, data[1:n+1]))
m = int(data[n+1])
queries = [tuple(map(int, data[n+2+2*i:n+4+2*i])) for i in range(m)]

# Giải bài toán
results = count_subarrays(n, a, m, queries)

# Xuất kết quả
sys.stdout.write('\n'.join(map(str, results)) + '\n')