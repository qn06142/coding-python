with open("CAU1.INP", "r") as f:
    a, b, c = tuple(int(i) for i in f.readline().split())
ans = 1
for i in range(a, b + 1):
    ans = ans * i % c

with open("CAU1.OUT", "w") as f:
    f.write(str(ans))