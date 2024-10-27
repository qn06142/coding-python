from fractions import Fraction
rt, rj, st, sj = map(Fraction, input().split())
if (rt - 1) / st == (rj - 1) / sj: print("SAME")
elif (rt - 1) / st > (rj - 1) / sj: print("JAKARTA")
else: print("TAOYUAN")