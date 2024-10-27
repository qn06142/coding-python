class LazySegmentTree:
    def __init__(self, array):
        self.n = len(array)
        self.tree = [0] * (4 * self.n)
        self.lazy = [0] * (4 * self.n)
        self.build(array, 0, 0, self.n - 1)

    def build(self, array, node, start, end):
        if start == end:
            self.tree[node] = array[start]
        else:
            mid = (start + end) // 2
            self.build(array, 2 * node + 1, start, mid)
            self.build(array, 2 * node + 2, mid + 1, end)
            self.tree[node] = max(self.tree[2 * node + 1], self.tree[2 * node + 2])

    def update_range(self, l, r, val, node, start, end):
        if self.lazy[node] != 0:
            self.tree[node] += self.lazy[node]
            if start != end:
                self.lazy[2 * node + 1] += self.lazy[node]
                self.lazy[2 * node + 2] += self.lazy[node]
            self.lazy[node] = 0

        if start > end or start > r or end < l:
            return

        if start >= l and end <= r:
            self.tree[node] += val
            if start != end:
                self.lazy[2 * node + 1] += val
                self.lazy[2 * node + 2] += val
            return

        mid = (start + end) // 2
        self.update_range(l, r, val, 2 * node + 1, start, mid)
        self.update_range(l, r, val, 2 * node + 2, mid + 1, end)
        self.tree[node] = max(self.tree[2 * node + 1], self.tree[2 * node + 2])

    def query_range(self, l, r, node, start, end):
        if start > end or start > r or end < l:
            return float('-inf')

        if self.lazy[node] != 0:
            self.tree[node] += self.lazy[node]
            if start != end:
                self.lazy[2 * node + 1] += self.lazy[node]
                self.lazy[2 * node + 2] += self.lazy[node]
            self.lazy[node] = 0

        if start >= l and end <= r:
            return self.tree[node]

        mid = (start + end) // 2
        left_query = self.query_range(l, r, 2 * node + 1, start, mid)
        right_query = self.query_range(l, r, 2 * node + 2, mid + 1, end)
        return max(left_query, right_query)

import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    a = list(map(int, data[1:n+1]))
    q = int(data[n+1])
    
    queries = data[n+2:]
    
    seg_tree = LazySegmentTree(a)
    index = 0
    results = []
    
    for _ in range(q):
        t = int(queries[index])
        if t == 1:
            l = int(queries[index + 1]) - 1
            r = int(queries[index + 2]) - 1
            v = int(queries[index + 3])
            seg_tree.update_range(l, r, v, 0, 0, n - 1)
            index += 4
        elif t == 2:
            l = int(queries[index + 1]) - 1
            r = int(queries[index + 2]) - 1
            result = seg_tree.query_range(l, r, 0, 0, n - 1)
            results.append(result)
            index += 3
    
    for res in results:
        print(res)

if __name__ == "__main__":
    main()