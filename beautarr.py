n = int(input())

a = tuple(int(i) for i in input().split())
def yeag(arr, n):
    count = 0
    for l in range(n):
        freq = {}
        for r in range(l, n):
            if arr[r] in freq:
                freq[arr[r]] += 1
            else:
                freq[arr[r]] = 1
            if freq[arr[r]] > 2:
                break
            else:
                count += 1
    return count
print(yeag(a, n))