class Node:
    def __init__(self, open=0, close=0):
        self.open = open
        self.close = close

def combine(l, r):
    loss = min(l.open, r.close)
    return Node(l.open - loss + r.open, r.close - loss + l.close)

def build(k, l, r):
    if l == r:
        if c[l-1] == '(':
            t[k] = Node(1, 0)
        else:
            t[k] = Node(0, 1)
        return
    m = (l+r)//2
    build(k*2, l, m)
    build(k*2+1, m+1, r)
    t[k] = combine(t[k*2], t[k*2+1])

def update(k, l, r, i, ch):
    if r < i or i < l:
        return
    if l == i and r == i:
        if ch == '(':
            t[k] = Node(1, 0)
        else:
            t[k] = Node(0, 1)
        return
    m = (l+r)//2
    update(k*2, l, m, i, ch)
    update(k*2+1, m+1, r, i, ch)
    t[k] = combine(t[k*2], t[k*2+1])

def get(k, l, r, L, R):
    if r < L or R < l:
        return Node(0, 0)
    if L <= l and r <= R:
        return t[k]
    m = (l+r)//2
    return combine(get(k*2, l, m, L, R), get(k*2+1, m+1, r, L, R))

n, m = map(int, input().split())
c = list(input().strip())

t = [Node() for _ in range(n*4+5)]

build(1, 1, n)

for _ in range(m):
    data = list(map(str, input().split()))
    if data[0] == '0':
        i = int(data[1])
        ch = '(' if c[i] == ')' else ')'
        c[i] = ch
        update(1, 1, n, i, ch)
    else:
        L, R = map(int, data[1:])
        res = get(1, 1, n, L, R)
        print(1 if res.open == 0 and res.close == 0 else 0, end = '')
