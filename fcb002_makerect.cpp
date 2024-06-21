def max_rectangle_area(N, A):
    from collections import Counter

    freq = Counter(A)

    lengths = []
    for length, count in freq.items():
        if count >= 2:
            lengths.append(length)

    lengths.sort(reverse=True)

    max_area = 0
    first = 0
    second = 0

    for length in lengths:
        pairs = freq[length] // 2
        for _ in range(pairs):
            if first == 0:
                first = length
            elif second == 0:
                second = length
                max_area = max(max_area, first * second)
                first = second
                second = 0

    return max_area

N = int(input())
A = list(map(int, input().split()))

print(max_rectangle_area(N, A))