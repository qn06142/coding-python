n = int(input())
h = list(map(int, input().split()))
ans = [0] * n
stc = []
for i in range(n - 2, -1, -1):
    while stc and h[stc[-1]] < h[i + 1]:
        stc.pop()
    stc.append(i + 1)
    ans[i] = len(stc)
print(*ans)
