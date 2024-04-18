from collections import deque
input()
inp = [int(i) for i in input().split()]
currmax = 0
#for i in range(0,len(inp)):
#	for j in range(1,len(inp)-i+1):
#		if len(inp[i:i+j]) >= 4 and len(inp[i:i+j]) % 2 == 0:
#			currmax = max(sum(inp[i:i+j]), currmax)
def maxSumWithK(a, n, k):
  
    # maxSum[i] is going to store 
    # maximum sum till index i such
    # that a[i] is part of the sum.
    maxSum = [0 for i in range(n)]
    maxSum[0] = a[0]
 
    # We use Kadane's algorithm to fill maxSum[]
    # Below code is taken from method3 of
    # https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
    curr_max = a[0]
    for i in range(1, n):
     
        curr_max = max(a[i], curr_max + a[i])
        maxSum[i] = curr_max
 
    # Sum of first k elements
    sum = 0
    for i in range(k):
        sum += a[i]
 
    # Use the concept of sliding window
    result = sum
    for i in range(k, n, 2):
     
        # Compute sum of k elements 
        # ending with a[i].
        sum = sum + a[i] - a[i-k]
 
        # Update result if required
        result = max(result, sum)
 
        # Include maximum sum till [i-k] also
        # if it increases overall max.
        result = max(result, sum + maxSum[i-k])
     
    return result
print(maxSumWithK(inp, len(inp), 4))