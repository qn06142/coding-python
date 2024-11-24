def count_subarrays(n, M, a):
    left = 0
    current_sum = 0
    count = 0
    
    for right in range(n):
        current_sum += a[right]
        
        while current_sum > M:
            current_sum -= a[left]
            left += 1
        
        count += (right - left + 1)
    
    return count

# Đọc đầu vào
n, M = map(int, input().split())
a = list(map(int, input().split()))

# Tính toán và in kết quả
result = count_subarrays(n, M, a)
print(result)
