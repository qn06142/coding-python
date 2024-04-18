# Khởi tạo cây đoạn
def build(node, start, end):
    if start == end:
        min_tree[node] = max_tree[node] = height[start]
    else:
        mid = (start + end) // 2
        build(2*node, start, mid)
        build(2*node+1, mid+1, end)
        min_tree[node] = min(min_tree[2*node], min_tree[2*node+1])
        max_tree[node] = max(max_tree[2*node], max_tree[2*node+1])
inf = -1e18
# Truy vấn cây đoạn
def query(node, start, end, l, r):
    if r < start or end < l:
        return (inf, -inf)  # Trả về (min, max) = (inf, -inf) nếu đoạn [l, r] nằm ngoài [start, end]
    if l <= start and end <= r:
        return (min_tree[node], max_tree[node])  # Trả về (min, max) nếu đoạn [start, end] nằm trong [l, r]
    mid = (start + end) // 2
    p1 = query(2*node, start, mid, l, r)
    p2 = query(2*node+1, mid+1, end, l, r)
    return (min(p1[0], p2[0]), max(p1[1], p2[1]))  # Trả về (min, max) của hai đoạn con

# Đọc dữ liệu
N, Q = map(int, input().split())
height = list(map(int, input().split()))
min_tree = [0] * (4*N)
max_tree = [0] * (4*N)

# Xây dựng cây đoạn
build(1, 0, N-1)

# Xử lý truy vấn
for _ in range(Q):
    u, v = map(int, input().split())
    res = query(1, 0, N-1, u-1, v-1)
    print(res[1] - res[0])
