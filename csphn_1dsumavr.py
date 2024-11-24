size = int(input())
from itertools import accumulate
inp = list(map(int, input().split()))
ans = []
def DecodeOriginalArray(presum, N):
 
    # Calculating elements of original array
    for i in range(N - 1, 0, -1):
        presum[i] = presum[i] - presum[i - 1];
 
    # Displaying elements of original array
    for i in range(N):
        print(presum[i], end= " ");
def ans():
	for index, item in enumerate(inp):
		inp[index] = item*(index+1)
	DecodeOriginalArray(inp, size)
ans()