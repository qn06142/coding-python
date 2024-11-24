class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (n + 1)

    def update(self, idx, delta):
        while idx <= self.n:
            self.tree[idx] += delta
            idx += idx & -idx

    def query(self, idx):
        sum = 0
        while idx > 0:
            sum += self.tree[idx]
            idx -= idx & -idx
        return sum

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    m = int(data[1])
    a = [0] + [int(data[i]) for i in range(2, n + 2)]
    queries = data[n + 2:]
    
    fenwick_tree = FenwickTree(n)
    for i in range(1, n + 1):
        fenwick_tree.update(i, a[i])
    
    idx = 0
    result = []
    while idx < len(queries):
        T = int(queries[idx])
        if T == 1:
            i = int(queries[idx + 1])
            x = int(queries[idx + 2])
            delta = x - a[i]
            a[i] = x
            fenwick_tree.update(i, delta)
            idx += 3
        elif T == 2:
            K = int(queries[idx + 1])
            idx += 2
            left, right = 1, n
            best = 0
            while left <= right:
                mid = (left + right) // 2
                if fenwick_tree.query(mid) <= K:
                    best = mid
                    left = mid + 1
                else:
                    right = mid - 1
            result.append(fenwick_tree.query(best))
    
    sys.stdout.write('\n'.join(map(str, result)) + '\n')

if __name__ == "__main__":
    main()
