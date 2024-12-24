def equalrad(n, circles):

    intervals = [(x - r, x + r) for x, r in circles]

    intervals.sort(key=lambda interval: interval[1])

    count = 0
    last_end = float('-inf')  

    for start, end in intervals:
        if start >= last_end:  
            count += 1
            last_end = end  

    return count

import sys
input = sys.stdin.read
data = input().splitlines()

n = int(data[0])  
circles = [tuple(map(int, line.split())) for line in data[1:]]

result = equalrad(n, circles)
print(result)