def calculate_points(s):
    points = 0
    consecutive_wins = 0
    for match in s:
        if match == 'W':
            consecutive_wins += 1
            points += 2
            if consecutive_wins >= 3:
                points += 1
        elif match == 'D':
            consecutive_wins = 0
            points += 1
        else:
            consecutive_wins = 0
    return points

def brute_force(s):
    n = len(s)
    max_points = 0
    for i in range(1 << n):
        new_s = [s[j] for j in range(n) if (i & (1 << j)) != 0]
        max_points = max(max_points, calculate_points(new_s))
    return max_points

s = input().strip()
print(brute_force(s))
