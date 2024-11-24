n = int(input())
s = list(input())

srevers = s[::-1]
i = 0
j = 0
ans = 0
while i < n:
    j = i
    #find nearest letter to swap to reversed(better than looking at end)
    while (s[j] != srevers[i]):
        j += 1
    
    while i < j:
        tmp = s[j]
        s[j] = s[j - 1]
        s[j - 1] = tmp
        j -=1
        ans += 1
    i += 1

print(ans)
