def count_lucky_pairs(n, a, b):

    d = [a[i] - b[i] for i in range(n)]

    d.sort()

    count = 0

    i, j = 0, n - 1
    while i < j:
        if d[i] + d[j] > 0:
            count += j - i
            j -= 1
        else:
            i += 1

    return count

n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

result = count_lucky_pairs(n, a, b)
print(result)