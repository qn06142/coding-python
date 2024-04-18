def solve(s):
    n = len(s)
    chan = [0] * (n + 1)
    le = [0] * (n + 1)
    for i in range(1, n + 1):
        if i % 2 == 0:
            chan[i] = chan[i - 1] + int(s[i - 1])
            le[i] = le[i - 1]
        else:
            le[i] = le[i - 1] + int(s[i - 1])
            chan[i] = chan[i - 1]
    for i in range(1, n + 1):
        if le[i - 1] + chan[n] - chan[i] == chan[i - 1] + le[n] - le[i]:
            return i
    return 0

s = input()
print(solve(s))