import random
from typing import List, Tuple

# Define constants
ll = int
MAX = 100005
BIT = [0] * MAX
sum_arr = [0] * MAX
res = [0] * MAX
q = 0

class Node:
    def __init__(self, l: int, r: int, x: int, i: int):
        self.l = l
        self.r = r
        self.x = x
        self.i = i

query: List[Node] = []
save: List[Tuple[int, int]] = []

def cmp(a: Tuple[int, int], b: Tuple[int, int]) -> bool:
    return a[1] > b[1]

def dk(a: Node, b: Node) -> bool:
    return a.x > b.x

def build():
    for i in range(1, MAX // 2 + 1):
        for j in range(i * 2, MAX, i):
            sum_arr[j] += i
    for i in range(1, MAX + 1):
        save.append((i, sum_arr[i]))
    save.sort(key=lambda x: x[1], reverse=True)

def update(vt: int):
    while vt < MAX:
        BIT[vt] += 1
        vt += vt & -vt

def get(vt: int) -> int:
    s = 0
    while vt > 0:
        s += BIT[vt]
        vt -= vt & -vt
    return s

def inp():
    global q
    build()
    q = int(input())
    for _ in range(q):
        l, r, x = map(int, input().split())
        query.append(Node(l, r, x, len(query) + 1))
    query.sort(key=dk)
    vt = 0
    for x in save:
        while vt < q and query[vt].x >= x[1]:
            tmp = query[vt]
            res[tmp.i] = get(tmp.r) - get(tmp.l - 1)
            vt += 1
        update(x[0])
    for i in range(1, q + 1):
        print(res[i])


inp()

