def sum_lucky_numbers(N):
    def sum_to_n(n):
        return n * (n + 1) // 2

    def sum_divisible_by_k(n, k):
        n_k = n // k
        return k * sum_to_n(n_k)
    total_sum = sum_to_n(N - 1)

    return total_sum - sum_divisible_by_k(N - 1, 5) - sum_divisible_by_k(N + 3, 5) + sum_divisible_by_k(N, 15)

print(sum_lucky_numbers(int(input()))) 