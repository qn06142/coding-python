def find_smallest_multiple(n, S):
    S.sort()  

    dp = [float('inf')] * n
    result = [(-1, 0)] * n

    for digit in S:
        if digit != 0:
            mod = digit % n
            dp[mod] = 1
            result[mod] = (-1, digit)

    queue = [digit % n for digit in S if digit != 0]
    while queue:
        u = queue.pop(0)
        for digit in S:
            v = (u * 10 + digit) % n
            if dp[u] + 1 < dp[v]:
                dp[v] = dp[u] + 1
                queue.append(v)
                result[v] = (u, digit)

    if dp[0] == float('inf'):
        return -1
    else:
        ans = []
        idx = 0
        while idx != -1:
            ans.append(result[idx][1])
            idx = result[idx][0]
        return int("".join(map(str, ans[::-1])))

n = int(input())
S = list(map(int, input().strip()))
result = find_smallest_multiple(n, S)
print(result)