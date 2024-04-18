def count_triplets(positions):
    positions.sort()
    count = []
    n = len(positions)
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                if abs(positions[j] - positions[i]) <= abs(positions[k] - positions[j]) and abs(positions[j] - positions[i]) * 2 >= abs(positions[k] - positions[j]):
                    count.append((positions[i], positions[j], positions[k]))
    return count

positions = [int(input()) for i in range(0, int(input()))]
print(len(count_triplets(positions)))