def count_valid_subarrays(n, c, a):
    left = 0
    current_sum = 0
    count = 0
    
    for right in range(n):
        current_sum += a[right]
        
        while current_sum > c:
            current_sum -= a[left]
            left += 1
        
        count += (right - left + 1)
    
    return count

# Đọc đầu vào
n, c = map(int, input().split())
a = list(map(int, input().split()))

# Tính toán và in kết quả
result = count_valid_subarrays(n, c, a)
print(result)
