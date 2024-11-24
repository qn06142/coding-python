from math import comb

def calculate_N0(n, m):
    N0 = 0
    for r in range(n+1):
        for s in range(m+1):
            N0 += ((-1)**(r+s)) * comb(n, r) * comb(m, s) * (2**(r*s))
    return N0


print(calculate_N0(*(int(i) for i in input().split())))