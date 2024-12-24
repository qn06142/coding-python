from math import gcd
def solve():
    k, a, b = [int(i) for i in input().split()]
    ba_ = b - a
    while gcd(ba_, k) > 1:
        ba_ //= gcd(ba_, k)
    m = int(input())
    for _ in range(0, m):
        p, q= (int(i) for i in input().split())

        if q > p and (q - p) % ba_ == 0:# to future me: prove this again (it is hard) (please i beg you it is not as simple as it seems)
            print("YES") 
        else: 
            print("NO")
t = int(input())
for _ in range(0, t):
    solve()