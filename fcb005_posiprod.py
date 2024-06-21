def min_transformations_to_positive_product(N, A):
    count_positive = sum(1 for x in A if x > 0)
    count_negative = sum(1 for x in A if x < 0)
    count_zero = N - count_positive - count_negative

    if count_zero >= 1:
        return -1

    transformations_to_all_positive = count_negative + (1 if count_zero == 1 else 0)
    transformations_to_all_negative = count_positive + (1 if count_zero == 1 else 0)

    return min(transformations_to_all_positive, transformations_to_all_negative)

N = int(input())
A = list(map(int, input().split()))

result = min_transformations_to_positive_product(N, A)
print(result)