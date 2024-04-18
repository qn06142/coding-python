n = int(input())
s = input()
x, y = input().split()
x_positions = [i for i in range(n) if s[i] == x]
y_positions = [i for i in range(n) if s[i] == y]

max_time = 0
for x_pos in x_positions:
    min_time = min(abs(x_pos - y_pos) for y_pos in y_positions)
    min_time = min(min_time, n - min_time)
    max_time = max(max_time, min_time)
print(max_time)