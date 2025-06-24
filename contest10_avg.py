import sys

def sum_digital_roots(a: int, b: int) -> int:
    if a > b:
        return 0

    a = max(a, 0)

    ans = 0

    if a == 0:
        ans += 0
        a = 1
    if a > b:
        return ans

    L, R = a, b
    N = R - L + 1
    ans += N  

    m0, m1 = L - 1, R - 1
    def calc(m0, m1):
        c0, c1 = divmod(m0, 9)[0], divmod(m1, 9)[0]
        r0, r1 = m0 % 9, m1 % 9

        if c0 == c1:
            return (r0 + r1) * (r1 - r0 + 1) // 2

        beg = (r0 + 8) * (8 - r0 + 1) // 2

        end = (0 + r1) * (r1 - 0 + 1) // 2

        mid = max(0, c1 - c0 - 1) * 36
        return beg + mid + end

    ans += calc(m0, m1)
    return ans

data = sys.stdin.read().split()
t = int(data[0])
idx = 1
out = []
for _ in range(t):
    a = int(data[idx]); b = int(data[idx+1])
    idx += 2
    out.append(str(sum_digital_roots(a, b)))
sys.stdout.write("\n".join(out))