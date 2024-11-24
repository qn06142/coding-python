import math

def find_optimal_location(islands):
    islands = [(x, y, x**2 + y**2) for x, y in islands]

    def calculate_radius(x):
        return max(math.sqrt(x - xi + yi2) for xi, _, yi2 in islands)

    def binary_search(left, right):
        eps = 1e-2

        while right - left > eps:
            mid1 = left + (right - left) / 3
            mid2 = right - (right - left) / 3

            radius1 = calculate_radius(mid1)
            radius2 = calculate_radius(mid2)

            if radius1 < radius2:
                right = mid2
            else:
                left = mid1

        return left, calculate_radius(left)

    min_x = min(x for x, _, _ in islands)
    max_x = max(x for x, _, _ in islands)

    x, radius = binary_search(min_x, max_x)

    return x, radius

n = int(input())
islands = [tuple(int(i) for i in input().split()) for _ in range(n)]

x, radius = find_optimal_location(islands)
print("{0:0.2f}".format(radius))
