from bisect import bisect_left, bisect_right
import sys

def maxSubarraySum(sum, k, row):

	curSum, curMax = 0, -sys.maxsize - 1

	sumSet = {}

	sumSet[0] = 1

	for r in range(row):

		curSum += sum[r]

		arr = list(sumSet.keys())

		it = bisect_left(arr, curSum - k)

		if (it != len(arr)):
			curMax = max(curMax, curSum - it)

		sumSet[curSum] = 1

	return curMax

def maxSumSubmatrix(matrix, k):

	row = len(matrix)
	col = len(matrix[0])

	ret = -sys.maxsize - 1

	for i in range(col):
		sum = [0] * (row)

		for j in range(i, col):

			for r in range(row):
				sum[r] += matrix[r][j]

			curMax = maxSubarraySum(sum, k, row)

			ret = max(ret, curMax)

	print(ret)

if __name__ == '__main__':

	matrix = [ [10, 8, 6, 8, 10]]
	K = 9

	maxSumSubmatrix(matrix, K)

