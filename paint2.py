n = int(input())
from string import ascii_lowercase

rooms = [''] * (10**6)
from heapq import heapify, heappop, heappush
latestempty = 
for _ in range(n):

    operation = input().split()

    if operation[0] == '1':

        color = operation[1]  
        for i in range(10**6):
            if rooms[i] == '':  
                rooms[i] = color
                break  

    elif operation[0] == '2':

        color_from = operation[1]
        color_to = operation[2]
        for i in range(10**6):
            if rooms[i] == color_from:
                rooms[i] = color_to

print(''.join(rooms))