def rotate(x):
    x = str(x)
    return int(x[1:] + x[0])

def transform(k, x, y, count=0):
    max_val = 10**k
    if x == y or count >= 10**6:
        return x, count
    if x < max_val:
        return transform(k, x+1, y, count+1)
    else:
        return transform(k, rotate(x), y, count+1)

k = 3
x = 123
y = 232
result, operations = brute_force(k, x, y)
if operations < 10**6:
    print(f"Đã biến đổi {x} thành {y} sau {operations} phép biến đổi.")
else:
    print("Không thể biến đổi X thành Y trong 10^6 phép biến đổi.")
