import sys

def solve(n, s):

    if s == 0:
        return "0" if n == 1 else "-1"
    if s > 9 * n:
        return "-1"

    res = []
    rem = s
    for i in range(1, n+1):
        left = n - i
        low = 1 if i == 1 and n > 1 else 0

        need = rem - 9 * left
        d = max(low, need)
        if d > 9: 
            d = 9  
        res.append(str(d))
        rem -= d

    return "".join(res)

data = sys.stdin.read().strip().split()
if not data:
    sys.exit(0)
n = int(data[0]); s = int(data[1])
print(solve(n, s))