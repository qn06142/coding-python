with open("TIMY.INP") as f:
    x, n = map(int, f.read().split())

if n % x == 0 and n // x >= 1:
    ans = str(n // x)
else:
    ans = "NA"

with open("TIMY.OUT", "w") as f:
    f.write(ans)
