import sys
import concurrent.futures
import matplotlib.pyplot as plot

sys.set_int_max_str_digits(10**9)

MOD = 123456789

def solve_with_string_mod(n, k):
    n = list(map(int, str(n)))
    for _ in range(k):
        n = [i * 3 for i in n]
        n = list(map(int, str(int(''.join(map(str, n))))))
    return int(''.join(map(str, n))) % MOD

def solve_with_direct_mod(n, k):
    n = list(map(int, str(n)))
    result = 0
    for _ in range(k):
        for i in n:
            result = (result * 10 + i * 3) % MOD
        n = list(map(int, str(result)))
    return result

def compare_results(n, k_range):
    string_mod_results = []
    direct_mod_results = []

    for k in k_range:
        res_string_mod = solve_with_string_mod(n, k)
        res_direct_mod = solve_with_direct_mod(n, k)

        string_mod_results.append(res_string_mod)
        direct_mod_results.append(res_direct_mod)

        print(f"k={k}: String Mod = {res_string_mod}, Direct Mod = {res_direct_mod}, Difference = {res_string_mod - res_direct_mod}")

    return string_mod_results, direct_mod_results

if __name__ == "__main__":
    n = 1024
    max_k = 40
    k_range = range(max_k)

    string_mod_results, direct_mod_results = compare_results(n, k_range)

    plot.plot(k_range, string_mod_results, label='String Mod')
    plot.plot(k_range, direct_mod_results, label='Direct Mod', linestyle='dashed')
    plot.legend()
    plot.show()