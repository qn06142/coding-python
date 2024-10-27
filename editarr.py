MOD = int(1e9 + 7)

class SegmentTree:
    class Node:
        def __init__(self):
            self.sum = 0
            self.square = 0
            self.cube = 0
            self.lazyE = 1
            self.lazyF = 0
            self.len = 0

    def __init__(self, size):
        self.n = size
        self.tree = [self.Node() for _ in range(4 * self.n)]

    def build(self, id, l, r, a):
        if l == r:
            self.tree[id].sum = a[l]
            self.tree[id].square = (a[l] * a[l]) % MOD
            self.tree[id].cube = (a[l] * a[l] % MOD * a[l]) % MOD
            self.tree[id].len = 1
            return

        m = (l + r) // 2
        self.build(id * 2, l, m, a)
        self.build(id * 2 + 1, m + 1, r, a)

        self.tree[id].sum = (self.tree[id * 2].sum + self.tree[id * 2 + 1].sum) % MOD
        self.tree[id].square = (self.tree[id * 2].square + self.tree[id * 2 + 1].square) % MOD
        self.tree[id].cube = (self.tree[id * 2].cube + self.tree[id * 2 + 1].cube) % MOD
        self.tree[id].len = self.tree[id * 2].len + self.tree[id * 2 + 1].len

    def push(self, id, l, r):
        if self.tree[id].lazyE == 1 and self.tree[id].lazyF == 0:
            return

        m = (l + r) // 2
        self.apply(id * 2, l, m, self.tree[id].lazyE, self.tree[id].lazyF)
        self.apply(id * 2 + 1, m + 1, r, self.tree[id].lazyE, self.tree[id].lazyF)

        self.tree[id].lazyE = 1
        self.tree[id].lazyF = 0

    def apply(self, id, l, r, e, f):
        length = r - l + 1
        sum_val = self.tree[id].sum
        square = self.tree[id].square
        cube = self.tree[id].cube
        self.tree[id].sum = (sum_val * e % MOD + length * f) % MOD
        self.tree[id].square = (square * e * e + 2 * e * sum_val * f + f * f * length) % MOD
        self.tree[id].cube = (cube * e * e * e + 3 * e * e * square * f + 3 * e * sum_val * f * f + f * f * f * length) % MOD

        self.tree[id].lazyE = (self.tree[id].lazyE * e) % MOD
        self.tree[id].lazyF = (self.tree[id].lazyF * e + f) % MOD

    def update(self, id, l, r, u, v, e, f):
        if l > v or r < u:
            return
        if l >= u and r <= v:
            self.apply(id, l, r, e, f)
            return

        self.push(id, l, r)
        m = (l + r) // 2
        self.update(id * 2, l, m, u, v, e, f)
        self.update(id * 2 + 1, m + 1, r, u, v, e, f)
        self.tree[id].sum = (self.tree[id * 2].sum + self.tree[id * 2 + 1].sum) % MOD
        self.tree[id].square = (self.tree[id * 2].square + self.tree[id * 2 + 1].square) % MOD
        self.tree[id].cube = (self.tree[id * 2].cube + self.tree[id * 2 + 1].cube) % MOD

    def queryAll(self, id, l, r, u, v):
        if l > v or r < u:
            return (0, 0, 0)

        if l >= u and r <= v:
            return (self.tree[id].sum, self.tree[id].square, self.tree[id].cube)

        self.push(id, l, r)
        m = (l + r) // 2
        sumLeft, squareLeft, cubeLeft = self.queryAll(id * 2, l, m, u, v)
        sumRight, squareRight, cubeRight = self.queryAll(id * 2 + 1, m + 1, r, u, v)

        sum_val = (sumLeft + sumRight) % MOD
        square = (squareLeft + squareRight) % MOD
        cube = (cubeLeft + cubeRight) % MOD

        return (sum_val, square, cube)

    def query_range(self, l, r):
        sum_val, square, cube = self.queryAll(1, 0, self.n - 1, l, r)
        result = (sum_val * sum_val % MOD * sum_val % MOD - 3 * square % MOD * sum_val % MOD + 2 * cube % MOD) % MOD
        return (result + MOD) % MOD

    def update_range(self, l, r, e, f):
        self.update(1, 0, self.n - 1, l, r, e, f)


def main():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    st = SegmentTree(n)

    for i in range(n):
        st.update_range(i, i, 1, a[i])

    for _ in range(q):
        inp = input().strip().split()
        type_query = inp[0]
        l, r = map(int, inp[1:3])
        l -= 1
        r -= 1
        # debug(l, r, type_query)  # Uncomment if debug function is defined
        if type_query == 'U':
            v = int(inp[3])
            st.update_range(l, r, 1, v)
        elif type_query == 'M':
            v = int(inp[3])
            st.update_range(l, r, v, 0)
        elif type_query == 'A':
            v = int(inp[3])
            st.update_range(l, r, 0, v)
        elif type_query == 'C':
            print(st.query_range(l, r) * 166666668 % MOD)

if __name__ == "__main__":
    main()

