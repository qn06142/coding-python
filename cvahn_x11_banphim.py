def checkissubofstring(s, t):
    i = j = 0
    while i < len(s) and j < len(t):
        if s[i] != t[j]:
            return False
        count_s = count_t = 0
        while i < len(s) and s[i] == t[j]:
            i += 1
            count_s += 1
        while j < len(t) and t[j] == s[i - 1]:
            j += 1
            count_t += 1
        if count_t < count_s:
            return False
    return i == len(s) and j == len(t)

with open("banphim.inp", "r") as f:
    testcases = tuple((f.readline().strip(), f.readline().strip()) for _ in range(int(f.readline())))
with open("banphim.out", "w") as f:
    for s, t in testcases:
        f.write("YES\n" if checkissubofstring(s, t) else "NO\n")