def find_original_string(x, k):
    n = len(x)
    if k > n:
        return -1
    for i in range(n):
        s = x[i:] + x[:i]
        if sorted([s[j:] + s[:j] for j in range(n)])[k-1] == s:
            return s
    return -1

# Đọc dữ liệu từ tệp
with open('CAU5.INP', 'r') as f:
    k = int(f.readline().strip())
    x = f.readline().strip()

# Tìm xâu s
s = find_original_string(x, k)

# Ghi kết quả ra tệp
with open('CAU5.OUT', 'w') as f:
    f.write(str(s) if s != -1 else '-1')
