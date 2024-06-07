s = input()
n = len(s)
s = " " + s
cnt = (s[n] == '8')
ans = True

for i in range(1, n):
    ans = ans and ((s[i] == '6' or s[i] == '8') and (s[i] <= s[i+1]))
    cnt += (s[i] == '8')

ans = ans and (s[n] == '6' or s[n] == '8')

if not ans:
    print("NO")
else:
    print((n*(n+1))//2 + cnt)
