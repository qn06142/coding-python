import sys
input = sys.stdin.readline

n, q = map(int, input().split())
a = input().strip()
b = input().strip()

# Các ký tự có thể xuất hiện
letters = ['A', 'C', 'T']

# Tiền xử lý: tiền tố cho tần số của từng ký tự cho a và b
prefix_a = {ch: [0]*(n+1) for ch in letters}
prefix_b = {ch: [0]*(n+1) for ch in letters}
for i in range(n):
    for ch in letters:
        prefix_a[ch][i+1] = prefix_a[ch][i]
        prefix_b[ch][i+1] = prefix_b[ch][i]
    prefix_a[a[i]][i+1] += 1
    prefix_b[b[i]][i+1] += 1

# Các loại mismatch cần theo dõi: AC, CA, AT, TA, CT, TC
mismatch_types = ['AC', 'CA', 'AT', 'TA', 'CT', 'TC']
prefix_mismatch = {typ: [0]*(n+1) for typ in mismatch_types}

for i in range(n):
    for typ in mismatch_types:
        prefix_mismatch[typ][i+1] = prefix_mismatch[typ][i]
    if a[i] != b[i]:
        typ = a[i] + b[i]
        if typ in prefix_mismatch:
            prefix_mismatch[typ][i+1] += 1

# Trả lời truy vấn
out = []
for _ in range(q):
    # Đầu vào dùng 1-index, chuyển sang 0-index
    x, y = map(int, input().split())
    # Kiểm tra tần số ký tự
    valid = True
    for ch in letters:
        cnt_a = prefix_a[ch][y] - prefix_a[ch][x-1]
        cnt_b = prefix_b[ch][y] - prefix_b[ch][x-1]
        if cnt_a != cnt_b:
            valid = False
            break
    if not valid:
        out.append("-1")
        continue

    # Lấy số lượng lỗi cho từng loại
    cnt_AC = prefix_mismatch['AC'][y] - prefix_mismatch['AC'][x-1]
    cnt_CA = prefix_mismatch['CA'][y] - prefix_mismatch['CA'][x-1]
    cnt_AT = prefix_mismatch['AT'][y] - prefix_mismatch['AT'][x-1]
    cnt_TA = prefix_mismatch['TA'][y] - prefix_mismatch['TA'][x-1]
    cnt_CT = prefix_mismatch['CT'][y] - prefix_mismatch['CT'][x-1]
    cnt_TC = prefix_mismatch['TC'][y] - prefix_mismatch['TC'][x-1]

    direct = min(cnt_AC, cnt_CA) + min(cnt_AT, cnt_TA) + min(cnt_CT, cnt_TC)
    rem = (cnt_AC - min(cnt_AC, cnt_CA)) + (cnt_AT - min(cnt_AT, cnt_TA)) + (cnt_CT - min(cnt_CT, cnt_TC))
    ans = direct + 2 * rem
    out.append(str(ans))

print("\n".join(out))
