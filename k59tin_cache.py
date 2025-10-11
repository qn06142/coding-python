import sys
from collections import defaultdict, deque
INF = 10**18

data = sys.stdin.read().strip().split()
if not data:
    sys.exit(0)
it = iter(data)
n = int(next(it))
k = int(next(it))
a = [int(next(it)) for _ in range(k)]

pos_lists = defaultdict(deque)
for idx, val in enumerate(a):
    pos_lists[val].append(idx)

tools = set(a)

next_use = {}
for t in tools:
    next_use[t] = pos_lists[t][0] if pos_lists[t] else INF

cur_pos = {t: 0 for t in tools}

levels = [[] for _ in range(n+1)]
for t in tools:
    levels[0].append(t)

moves = 0

def pick_latest(level_list):
    global moves
    best = None
    best_val = -1
    for t in level_list:
        nu = next_use.get(t, INF)
        if nu > best_val:
            best_val = nu
            best = t
    return best

def Receive(j, x):
    global moves
    if j == 0:

        pass
    else:
        if len(levels[j]) >= 2:
            y = pick_latest(levels[j])

            Receive(j-1, y)

    upper = j+1

    try:
        levels[upper].remove(x)
    except ValueError:

        pass
    levels[j].append(x)
    cur_pos[x] = j
    moves += 1

def Request(i, x):
    global moves

    if cur_pos.get(x, 0) == i:
        return
    if len(levels[i]) >= 2:
        y = pick_latest(levels[i])

        Receive(i-1, y)

    Request(i-1, x)

    lower = i-1
    try:
        levels[lower].remove(x)
    except ValueError:

        pass
    levels[i].append(x)
    cur_pos[x] = i
    moves += 1

for idx, x in enumerate(a):

    pos_lists[x].popleft()
    next_use[x] = pos_lists[x][0] if pos_lists[x] else INF

    Request(n, x)

for level in range(n, 0, -1):

    while levels[level]:
        t = levels[level][0]

        while cur_pos[t] > 0:
            Receive(cur_pos[t]-1, t)

print(moves)