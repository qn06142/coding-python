prime = [0] * 100001

# Array to store the value of k 
# for each element in arr[]
k = [0] * 100001

# For value of k, Sieve implemented
def Sieve():

	# Initialize k[i] to i
	for i in range(1, 100001):
		k[i] = i

	# Prime sieve
	for i in range(2, 100001):

		# If i is prime then remove all
		# factors of prime from it
		if (prime[i] == 0):
			for j in range(i, 100001, i):

				# Update that j is not prime
				prime[j] = 1

				# Remove all square divisors 
				# i.e if k[j] is divisible by
				# i*i then divide it by i*i
				while (k[j] % (i * i) == 0):
					k[j] //= (i * i)

# Function that return total count of
# pairs with perfect square product
def countPairs (arr, n):

	# Store the frequency of k
	freq = dict()

	for i in range(n):
		if k[arr[i]] in freq.keys():
			freq[k[arr[i]]] += 1
		else:
			freq[k[arr[i]]] = 1

	Sum = 0

	# The total number of pairs is the 
	# summation of (fi * (fi - 1))/2
	for i in freq:
		Sum += (freq[i] * (freq[i] - 1)) / 2

	return Sum

n = int(input())
arr = list(range(1, n + 1))
arr += arr

# To pre-compute the value of k
Sieve()

# Function that return total count 
# of pairs with perfect square product 
print(int(countPairs(arr, n)))
