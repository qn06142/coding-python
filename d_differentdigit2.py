import sys
from functools import lru_cache
sys.setrecursionlimit(int(1e3 +5))
def solve():
    data = sys.stdin.readline().strip()
    MOD = 10**9 + 7
    n_str = data
    length = len(n_str)
    digits = list(map(int, n_str))

    @lru_cache(maxsize=None)
    def dp(idx: int, tight: bool, p1: int, p2: int, started: bool) -> int:

        if idx == length:
            return 1 if started else 0

        limit = digits[idx] if tight else 9
        total = 0

        for d in range(limit + 1):
            ntight = tight and (d == limit)
            nstarted = started or (d != 0)

            if not nstarted:

                total += dp(idx + 1, ntight, -1, -1, False)
            else:

                if d != p1 and d != p2:

                    if not started:

                        total += dp(idx + 1, ntight, d, -1, True)
                    else:

                        total += dp(idx + 1, ntight, d, p1, True)
        return total % MOD

    print(dp(0, True, -1, -1, False))

if __name__ == "__main__":
    solve()