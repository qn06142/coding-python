with open("doituyen.inp", "r") as f:
    n, q = tuple(int(i) for i in f.readline().split())
    a = sorted(int(i) for i in f.readline().split())
    queries = tuple(int(i) for i in f.readline().split())
from bisect import bisect_right
with open("doituyen.out", "w") as f:
    for i in queries:
        f.write(str(bisect_right(a, i)) + "\n")