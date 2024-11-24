def largest_prime_factor(n):
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
    return n

inp = int(open("uocnt.inp", "r").read())
largest_prime = largest_prime_factor(inp)

with open("uocnt.out", "w") as f:
    f.write(str(largest_prime))
