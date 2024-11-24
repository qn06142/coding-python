inp = input()
primes1 = set()
def sieve(num):
    prime = [True for i in range(num+1)]
# boolean array
    p = 2
    while (p * p <= num):
 
        # If prime[p] is not
        # changed, then it is a prime
        if (prime[p] == True):
 
            # Updating all multiples of p
            for i in range(p * p, num+1, p):
                prime[i] = False
        p += 1
 
    # Print all prime numbers
    for p in range(2, num+1):
        if prime[p]:
            primes1.add(int(p))
sieve(int(inp))
count = 0
for i in range(0, len(inp)):
	for j in range(i, len(inp)+1):
		currstr = inp[i:j]
		if currstr:
			if int(currstr) in primes1:
				count+=1
if count:
	print(count)
else:
	print("No primes")