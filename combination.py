class SegmentTree:
    def __init__(self, n):
        self.size = 1 << (n.bit_length() + 1)
        self.tree = [0] * self.size

    def update(self, idx, val):
        idx += self.size // 2
        self.tree[idx] = val
        while idx > 1:
            idx //= 2
            self.tree[idx] = self.tree[2 * idx] ^ self.tree[2 * idx + 1]

    def query(self, k):
        idx = 1
        while idx < self.size // 2:
            left_child = 2 * idx
            if self.tree[left_child] >= k:
                idx = left_child
            else:
                k -= self.tree[left_child]
                idx = left_child + 1
        return self.tree[idx]

def main():
    Q = int(input())
    segtree = SegmentTree(1 << 30)
    seed = 0

    for _ in range(Q):
        t, x = map(int, input().split())
        if t == 1:
            segtree.update(x ^ seed, x ^ seed)
        else:
            ans = segtree.query(x)
            print(ans)
            seed ^= ans

if __name__ == "__main__":
    main()
