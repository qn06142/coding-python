with open("CAU2.INP", "r") as f:
    n = int(f.readline().strip())
    a = [int(i) for i in f.readline().split()]

pref = [a[0]]
for i in range(1, n):
    pref.append(max(a[i], pref[i - 1]))
print(*pref)
with open("CAU2.OUT", "w") as f:
    f.write(" ".join(str(i) for i in pref))