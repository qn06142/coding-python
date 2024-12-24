class BIT2D:
    def __init__(self, rows, cols):
        """
        Initialize a 2D Binary Indexed Tree (BIT) for tracking maximum values.

        :param rows: Number of rows in the grid.
        :param cols: Number of columns in the grid.
        """
        self.rows = rows
        self.cols = cols
        self.tree = [[float('-inf')] * (cols + 1) for _ in range(rows + 1)]

    def update(self, row, col, value):
        """
        Update the value at position (row, col) to ensure it reflects the maximum value.

        :param row: Row index (1-based).
        :param col: Column index (1-based).
        :param value: The new value to consider at the specified position.
        """
        i = row
        while i <= self.rows:
            j = col
            while j <= self.cols:
                self.tree[i][j] = max(self.tree[i][j], value)
                j += j & -j
            i += i & -i

    def query(self, row, col):
        """
        Find the maximum value in the prefix range from (1,1) to (row, col).

        :param row: Row index (1-based).
        :param col: Column index (1-based).
        :return: The maximum value in the prefix range.
        """
        result = float('-inf')
        i = row
        while i > 0:
            j = col
            while j > 0:
                result = max(result, self.tree[i][j])
                j -= j & -j
            i -= i & -i
        return result

n = int(input())
s = list(int(i) for i in input())

a = []
for i in range(0, len(s)):
    s_ = 0
    for j in range(i, len(s)):
        s_ = s_ * 10 + s[j]
        a.append((s_, i, j))

a.sort()

b = [[0 for _ in range(n)] for _ in range(n)]
ranks = dict()
for rank, (value, start, end) in enumerate(a):
    if value not in ranks:
        ranks[value] = rank
    b[start][end] = ranks[value]

dp = [[1 for _ in range(n)] for _ in range(n)]
ans = 0

bit = BIT2D(n + 5, len(a) + 5)

for i in range(0, n):
    for j in range(i, n):

        max_dp = bit.query(i, b[i][j])
        #print(i, j, max_dp)
        #print(s[i:j])
        if max_dp != float('-inf'):
            dp[i][j] = max(dp[i][j], max_dp + 1)

        ans = max(ans, dp[i][j])
    for j in range(i, n):
        bit.update(j + 1, b[i][j] + 1, dp[i][j])  

print(ans)