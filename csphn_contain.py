
a = list(map(int, input().split()))


segments = []
for i in range(0, 8, 2):
    x, y = a[i], a[i + 1]
    segments.append((min(x, y), max(x, y)))


segments.sort()


merged = []
current_start, current_end = segments[0]
for start, end in segments[1:]:
    if start <= current_end:  
        current_end = max(current_end, end)
    else:
        merged.append((current_start, current_end))
        current_start, current_end = start, end
merged.append((current_start, current_end))


result = sum(end - start + 1 for start, end in merged)


print(result)
