def maximize_bananas(t, test_cases):
    results = []
    for a, b, c in test_cases:
        max_product = a * b * c

        for i in range(6):
            for j in range(6 - i):
                for k in range(6 - i - j):
                    new_a = a + i
                    new_b = b + j
                    new_c = c + k
                    current_product = new_a * new_b * new_c
                    if current_product > max_product:
                        max_product = current_product
        results.append(max_product)
    return results

t = int(input().strip())
test_cases = [tuple(map(int, input().strip().split())) for _ in range(t)]
results = maximize_bananas(t, test_cases)
for result in results:
    print(result)