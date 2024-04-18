def generate_binary(n):
    if n <= 0:
        return []
    elif n == 1:
        return ['0', '1']
    else:
        return [digit+bitstring for digit in generate_binary(1) for bitstring in generate_binary(n-1)]

for i in generate_binary(int(input())):
    print(i)
