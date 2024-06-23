def find_medians(n, a):
    result = [0] * n
    
    for i in range(n):
        smaller_count = 0
        larger_count = 0
        median_count = 0
        
        for j in range(i, n):
            if a[j] < a[i]:
                smaller_count += 1
            elif a[j] > a[i]:
                larger_count += 1
            else:
                median_count += 1
            
            if smaller_count <= median_count - 1 and larger_count <= median_count - 1:
                result[i] += 1
    
    return result

# Đọc input
n = int(input().strip())
a = list(map(int, input().strip().split()))

# Tìm và in kết quả
result = find_medians(n, a)
print(" ".join(map(str, result)))