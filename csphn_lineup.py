def lineup(n, h):
    stack = []
    res = [0]*n
    for i in range(n-1, -1, -1):
        while stack and h[stack[-1]] < h[i]:
            res[stack.pop()] = i + 1
        stack.append(i)
    return res

n = int(input())
h = list(map(int, input().split()))

res = lineup(n, h)

print(' '.join(map(str, res)))
