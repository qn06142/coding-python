from decimal import Decimal, getcontext
import math

getcontext().prec = 50

class Bottle:
    def __init__(self, h=Decimal(0), r=Decimal(0)):
        self.h = Decimal(h)
        self.r = Decimal(r)
        self.v = Decimal(math.pi) * self.h * self.r * self.r

eps = Decimal('1e-7')

def check(x, bottles, n, m):
    cnt = 0
    for i in range(1, n + 1):
        vol = bottles[i].v
        cnt += int(vol // x)
    return cnt >= m

def main():

    with open("CAINGHIEN.INP", "r") as fin:
        data = fin.read().split()

    n = int(data[0])
    m = int(data[1])

    bottles = [Bottle() for _ in range(n + 1)]
    index = 2
    for i in range(1, n + 1):
        x = Decimal(data[index])
        y = Decimal(data[index + 1])
        bottles[i] = Bottle(x, y)
        index += 2

    l, r = Decimal(0), Decimal('1e18')
    ans = Decimal(-1)

    for _ in range(45):
        mid = (l + r) / 2
        if check(mid, bottles, n, m):
            l = mid
            ans = mid
        else:
            r = mid

    with open("CAINGHIEN.OUT", "w") as fout:
        fout.write(f"{ans:.8f}\n")

if __name__ == "__main__":
    main()