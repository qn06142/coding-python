n = input()
m = input()
s = ""

while n and m:
    if n[0] <= m[0]:
        s += n[0]
        n = n[1:]
    else:
        s += m[0]
        m = m[1:]

if n:
    s += n
elif m:
    s += m

print(s)
