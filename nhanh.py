import sys
input_data = sys.stdin.read().strip().split()
it = iter(input_data)
n = int(next(it))

bit_masks = [0] * n
for i in range(n):
    row_value = 0
    for j in range(n):
        val = int(next(it))
        if val == 1:
            row_value |= (1 << j)
    bit_masks[i] = row_value

mask = (1 << n) - 1  

for i in range(n):
    for j in range(n):
        if i == j:
            continue

        if bit_masks[i] & (1 << j):

            candidate = bit_masks[j] & ((~bit_masks[i]) & mask)

            if candidate:

                k = (candidate & -candidate).bit_length() - 1

                print(i + 1, j + 1, k + 1)
                sys.exit()

print("-1 -1 -1")

    