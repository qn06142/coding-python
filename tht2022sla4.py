def smallest_divisible_by_4(N):
    N = str(N)
    len_N = len(N)

    def is_valid(num):
        return len(num) == len_N and num[0] != '0'

    def check_divisibility(num):
        return int(num[-2:]) % 4 == 0 if len(num) > 1 else int(num) % 4 == 0

    smallest_number = int(N)

    for i in range(len_N):
        for j in range(10):
            new_num1 = N[:i] + str(j) + N[i+1:]
            if is_valid(new_num1) and check_divisibility(new_num1):
                smallest_number = min(smallest_number, int(new_num1))
            for k in range(i+1, len_N):
                for l in range(10):
                    new_num2 = N[:i] + str(j) + N[i+1:k] + str(l) + N[k+1:]
                    if is_valid(new_num2) and check_divisibility(new_num2):
                        smallest_number = min(smallest_number, int(new_num2))

    return smallest_number

N = int(input().strip())
print(smallest_divisible_by_4(N))