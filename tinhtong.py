def sum_divisible_by_n(n, x):
    return n * (x // n) * ((x // n) + 1) // 2

def sum_numbers(A, B):
    total_2_B = sum_divisible_by_n(2, B)
    total_2_A = sum_divisible_by_n(2, A)
    total_6_B = sum_divisible_by_n(6, B)
    total_6_A = sum_divisible_by_n(6, A)
    return (total_2_B - total_2_A) - (total_6_B - total_6_A) - B
print(sum_numbers(int(input()), int(input())))