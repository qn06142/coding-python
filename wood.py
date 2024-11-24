from math import gcd, log2
from functools import reduce

def build_sparse_table(a):
    n = len(a)
    log_n = int(log2(n)) + 1
    sparse_table = [[0] * log_n for _ in range(n)]
    
    for i in range(n):
        sparse_table[i][0] = a[i]
    
    j = 1
    while (1 << j) <= n:
        i = 0
        while (i + (1 << j) - 1) < n:
            sparse_table[i][j] = gcd(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1])
            i += 1
        j += 1
    
    return sparse_table

def query_gcd(sparse_table, L, R):
    j = int(log2(R - L + 1))
    return gcd(sparse_table[L][j], sparse_table[R - (1 << j) + 1][j])

def find_segments(a):
    n = len(a)
    sparse_table = build_sparse_table(a)
    
    max_length = 0
    segments = []
    
    for l in range(n):
        low, high = l, n - 1
        while low <= high:
            mid = (low + high) // 2
            segment_gcd = query_gcd(sparse_table, l, mid)
            
            if all(a[i] % segment_gcd == 0 for i in range(l, mid + 1)):
                if (mid - l) > max_length:
                    max_length = mid - l
                    segments = [l + 1]  # +1 to convert 0-based index to 1-based
                elif (mid - l) == max_length:
                    segments.append(l + 1)
                low = mid + 1
            else:
                high = mid - 1

    return len(segments), max_length, segments

# Đọc dữ liệu đầu vào
n = int(input())
a = list(map(int, input().split()))

# Tìm các đoạn thỏa mãn điều kiện
k, max_length, segments = find_segments(a)

# In kết quả
print(k, max_length)
print(' '.join(map(str, segments)))
