import sympy
limit = 1e7
primes = list(sympy.primerange(1, limit))

# Find the product of all primes below the limit
largest_number = 1
for prime in primes:
    largest_number *= prime
    if(largest_number > limit):
        largest_number //= prime
        break
print(f"Largest number: {largest_number}")