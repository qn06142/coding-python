inp = int(input())
cases = []
cases = [int(input()) for i in range(0, inp)]
ans = []
for n in cases:
    output = []
    for i in range(1, n):
        for j in range(i, n):
            if 2*i + 2*j == n:
                output.append(i*j)
    if not not output:
        ans.append(sorted(output))
    else:
        ans.append([-1])
for i in ans:
    out = ""
    for j in i:
        out = out + str(j) + ' '
    print(out)
