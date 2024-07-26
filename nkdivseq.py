import math

def findNthNumber(N):
    q = math.ceil((math.sqrt(1 + 8 * N) - 1) / 2)
    
    a = q * N - q * (q * (q + 1) // 6)
    
    return a

N = int(input().strip())
print(findNthNumber(N))
