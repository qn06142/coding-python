m, n, t = map(int, input().split())
garden = [list(map(int, input().split())) for _ in range(m)]
move_count = 0

def count(line):
    streaks = [False] * len(line)
    current_type = 0
    current_count = 0

    for i in range(len(line)):
        if line[i] == current_type and line[i] != 0:
            current_count += 1
        else:
            if current_count >= t:
                for j in range(i - current_count, i):
                    streaks[j] = True
            current_type = line[i]
            current_count = 1 if line[i] != 0 else 0

    if current_count >= t:
        for j in range(len(line) - current_count, len(line)):
            streaks[j] = True

    return streaks

valid_positions = [[False] * n for _ in range(m)]

for i in range(m):
    row_streaks = count(garden[i])
    for j in range(n):
        if row_streaks[j]:
            valid_positions[i][j] = True

for j in range(n):
    col = [garden[i][j] for i in range(m)]
    col_streaks = count(col)
    for i in range(m):
        if col_streaks[i]:
            valid_positions[i][j] = True

for i in range(m):
    for j in range(n):
        if garden[i][j] != 0 and not valid_positions[i][j]:
            move_count += 1

print(move_count)
