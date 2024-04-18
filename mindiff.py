def minDiff(arr,n,k): 
	result = float('inf')
	arr.sort() 
	for i in range(n-k+1): 
		result = int(min(result, arr[i+k-1] - arr[i])) 
	return result 
n, k = tuple(int(i) for i in input().split())
arr = [int(i) for i in input().split()]
print(minDiff(arr, n, k)) 
