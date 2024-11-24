#include <iostream>
using namespace std;

const int MOD = 29;

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long sum_of_divisors_mod(long long X, long long mod) {
    long long two_exp = 2 * X + 1;
    long long three_exp = X + 1;
    long long one_sixty_seven_exp = X + 1;

    long long sum_2 = (mod_exp(2, two_exp, mod) - 1 + mod) % mod;
    sum_2 = (sum_2 * mod_exp(1, mod - 2, mod)) % mod;

    long long sum_3 = (mod_exp(3, three_exp, mod) - 1 + mod) % mod;
    sum_3 = (sum_3 * mod_exp(2, mod - 2, mod)) % mod;

    long long sum_167 = (mod_exp(167, one_sixty_seven_exp, mod) - 1 + mod) % mod;
    sum_167 = (sum_167 * mod_exp(166, mod - 2, mod)) % mod;

    long long total_sum = (sum_2 * sum_3 % mod) * sum_167 % mod;
    return total_sum;
}

int main() {
    long long X;
    while (true) {
        cin >> X;
        if (X == 0) {
            break;
        }
        cout << sum_of_divisors_mod(X, MOD) << endl;
    }
    return 0;
}