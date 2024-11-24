from itertools import combinations
import sys

def min_score(n, k, a):
    min_score = sys.maxsize
    for comb in combinations(a, k):
        Minh = list(comb)
        Nhan = [ai for ai in a if ai not in Minh]
        score = sum(abs(ai - aj) for ai in Minh for aj in Nhan)
        min_score = min(min_score, score)
    return min_score

n, k = map(int, input().split())
a = list(map(int, input().split()))
print(min_score(n, k, a))
