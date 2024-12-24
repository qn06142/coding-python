MOD = 10**9 + 7

def preprocess_powers_of_2(max_digits):
    pow2 = [2]  
    for i in range(1, max_digits):
        pow2.append(pow(pow2[-1], 10, MOD))  
    return pow2

def mod_exp_digitwise(base, exp_str, precomputed_powers):
    result = 1
    current_index = 0  

    for digit in reversed(exp_str):  
        digit = int(digit)
        if digit > 0:
            result = (result * pow(precomputed_powers[current_index], digit, MOD)) % MOD
        current_index += 1

    return result

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()

    t = int(data[0])
    results = []

    max_digits = 101
    precomputed_powers = preprocess_powers_of_2(max_digits)

    for i in range(1, t + 1):
        n = data[i]  

        exp_str = str(int(n) - 1)  
        power_of_two = mod_exp_digitwise(2, exp_str, precomputed_powers)

        result = (int(n) * power_of_two) % MOD
        results.append(result)

    sys.stdout.write("\n".join(map(str, results)) + "\n")

solve()