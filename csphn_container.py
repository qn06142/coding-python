
m, w, n = (int(i) for i in input().split())
seg = [0 for i in range(0, n * 4)]
m = min(m, n)

def build(node = 1, l = 1, r = m) -> None:
    if l == r:
        seg[node] = w
    else:
        mid = (l + r) // 2
        build(node * 2, l, mid)
        build(node * 2 + 1, mid + 1, r)
        seg[node] = max(seg[node * 2], seg[node * 2 + 1])
def get(x, node = 1, l = 1, r = m) -> int:
    if l == r:
        if seg[node] < x:
            return -1
        seg[node] -= x
        return l
    mid = (l + r) // 2

    ans = -1

    if seg[node * 2] >= x:
        ans = get(x, node * 2, l, mid)
    elif seg[node * 2 + 1] >= x:
        ans = get(x, node * 2 + 1, mid + 1, r)
    seg[node] = max(seg[node * 2], seg[node * 2 + 1])
    return ans
build()
for i in range(0, n):
    x = int(input())
    pos = get(x)
    if pos == -1:
        print(-1)
    else:
        print(pos)