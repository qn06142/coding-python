def longest_repeating_substring(s):
    length = len(s)
    for i in range(length // 2, 0, -1):
        for j in range(0, length - i + 1):
            substring = s[j:j+i]
            if s.count(substring) * len(substring) == length:
                return substring
    return "0"

with open("XAUGHEP.INP", "r") as f:
    inp = f.read().strip()

ans = longest_repeating_substring(inp)

with open("xaughep.out", "w") as f:
    f.write(ans)
