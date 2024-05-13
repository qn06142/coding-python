class SegmentTree:
    def __init__(self, n):
        self.seq = [0 for _ in range(0, 4*n)]
        self.n = n

    def build(self, a, node, l, r):
        if l == r:
            self.seq[node] = a[l]
        else:
            mid = (l + r) // 2
            self.build(a, node * 2, l, mid)
            self.build(a, node * 2 + 1, mid + 1, r)
            self.seq[node] = max(self.seq[node * 2], self.seq[node * 2 + 1])

    def update(self, x, y, node = 1, l = 1, r = None):
        if r is None:
            r = self.n
        if l == r:
            self.seq[node] = y
        else:
            mid = (l + r) // 2
            if x > mid:
                self.update(x, y, node * 2 + 1, mid + 1, r)
            else:
                self.update(x, y, node * 2, l, mid)
            self.seq[node] = max(self.seq[node * 2], self.seq[node * 2 + 1])

    def getmax(self, x, y, node = 1, l = 1, r = None):
        if r is None:
            r = self.n
        if x > r or y < l:
            return float('-inf')
        if x <= l and y >= r:
            return self.seq[node]
        mid = (l + r) // 2
        L = self.getmax(x, y, node * 2, l, mid)
        R = self.getmax(x, y, node * 2 + 1, mid + 1, r)
        return max(L, R)

def max_tower_height(n, bricks):
    bricks.sort()
    dp = [0]*(n + 5)
    parent = [-1]*n
    segtree = SegmentTree(n)
    for i in range(1, n + 1):
        dp[i] = segtree.getmax(1, bricks[i-1][1]) + bricks[i-1][2]
        segtree.update(bricks[i-1][0], dp[i])
    max_height = max(dp)
    max_index = dp.index(max_height)
    tower = []
    while max_index != -1:
        tower.append(bricks[max_index-1][3])
        max_index = parent[max_index]
    tower.reverse()
    return max_height, tower

n = int(input())
bricks = []
for i in range(n):
    ai, bi, hi = tuple(int(i) for i in input().split())
    bricks.append((ai, bi, hi, i + 1))
height, tower = max_tower_height(n, bricks)
print(height)
print(*tower)
