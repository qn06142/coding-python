import math

def calculate_marble_difference(M, N, U, V, R):
    total_marble = M * N
    marble_inside_circle = 0

    for i in range(1, N+1):
        for j in range(1, M+1):
            distance = math.sqrt((i-U)**2 + (j-V)**2)
            if distance <= R:
                marble_inside_circle += 1

    marble_outside_circle = total_marble - marble_inside_circle
    marble_difference = abs(marble_outside_circle - marble_inside_circle)

    return marble_difference
M = 10
N = 10
U = 5
V = 5
R = 3

print(calculate_marble_difference(M, N, U, V, R))
