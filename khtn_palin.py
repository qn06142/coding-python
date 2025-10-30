def solve(n):
    s = str(n)
    m = len(s)
    half = (m + 1) // 2
    first = s[:half]

    def make_pal(half, len):
        if len % 2 == 0:
            return half + half[::-1]
        else:
            return half + half[-2::-1]

    pal = int(make_pal(first, m))
    if pal > n:
        return pal

    inc = str(int(first) + 1)
    if len(inc) > half:

        return int("1" + ("0" * (m - 1)) + "1")
    return int(make_pal(inc, m))
import sys
sys.set_int_max_str_digits(0)
print(solve(int(input())))