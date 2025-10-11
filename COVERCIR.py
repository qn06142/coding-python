import sys

data = list(map(int, sys.stdin.buffer.read().split()))
t = data[0]
idx = 1
out = []
for _ in range(t):
    n = data[idx]; u = data[idx+1]; v = data[idx+2]
    idx += 3
    diff = abs(u - v)
    d = diff if diff <= n - diff else n - diff
    L = n - d
    ans = (L + 1) // 2   
    out.append(str(ans))
sys.stdout.write("\n".join(out))