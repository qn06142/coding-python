from bisect import bisect_right

def count_triplets(positions):
    positions.sort()
    n = len(positions)
    count = 0
    for i in range(n):
        for j in range(i+1, n):
            # Find the index of the first position that is greater than positions[i] + positions[j]
            k = bisect_right(positions, positions[i] + positions[j])
            # The number of positions between j and k are the triplets (i, j, z) where z is in the range [j+1, k)
            count += k - j - 1
    return count

positions = [int(input()) for i in range(0, int(input()))]
print(count_triplets(positions))