from typing import List, Tuple

def count_oaks(N: int, oaks: List[Tuple[int, int]], P: int, paths: List[Tuple[int, int, int, int]]) -> List[int]:
    result = []
    for path in paths:
        X1, Y1, X2, Y2 = path
        count = 0
        for oak in oaks:
            Xi, Yi = oak
            if X1 <= Xi <= X2 and Y1 <= Yi <= Y2:
                count += 1
        result.append(count)
    return result

N = int(input())

oaks = tuple(tuple(int(i) for i in input().split()) for _ in range (0, N))
P = int(input())
paths = tuple(tuple(int(i) for i in input().split()) for _ in range (0, P))
result = count_oaks(N, oaks, P, paths)

for i, count in enumerate(result):
    print(count)
