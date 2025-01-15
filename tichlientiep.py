from math import isqrt

with open("TICHLIENTIEP.INP", 'r') as f:
    n = int(f.read().strip())

ans = -1

for i in range(1, isqrt(n) + 1):  
    if i * (i + 1) == n:
        ans = i
        break

with open("TICHLIENTIEP.OUT", "w") as f:
    f.write(str(ans))