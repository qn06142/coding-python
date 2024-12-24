from collections import defaultdict

def count_rectangles(points):
    n = len(points)
    compress = []
    x_coordinates = defaultdict(list)
    for x, y in points:
        x_coordinates[x].append(y)

    unique_x = sorted(x_coordinates.keys())

    ans = 0

    for i in range(len(unique_x)):
        xi = unique_x[i]
        y_count = defaultdict(int)
        for y in x_coordinates[xi]:
            y_count[y] += 1

        for j in range(i + 1, len(unique_x)):
            y_count1 = defaultdict(int)
            common_y_pairs = 0

            for y in x_coordinates[unique_x[j]]:
                if y_count[y] > 0:
                    y_count1[y] += 1
            res = 0;
            for i in y_count1:
                for j in y_count1:
                    if i != j:
                        res += y_count1[i] * y_count1[j]
            ans += res // 2

    return ans

n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]

print(count_rectangles(points))
