s = input()
ans = 0
for i in ['A', 'T', 'G', 'C']:
    s_ = ''.join(' ' if j != i else j for j in s)
    if(s_.split() == 0):
        continue
    ans = max(ans, len(max(s_.split(), key = len, default='')))
print(ans)