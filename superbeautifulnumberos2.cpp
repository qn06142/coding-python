#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Sieve of Eratosthenes to find all prime numbers up to a given limit
vector<int> sieve_of_eratosthenes(int limit) {
    vector<bool> is_prime(limit + 1, true);
    vector<int> prime_numbers;
    
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers
    for (int p = 2; p * p <= limit; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }
    
    for (int p = 2; p <= limit; ++p) {
        if (is_prime[p]) {
            prime_numbers.push_back(p);
        }
    }
    
    return prime_numbers;
}

int count_super_beautiful_numbers(long long n) {
    int limit_q = cbrt(n) + 1; // calculate cube root of n
    vector<int> prime_numbers = sieve_of_eratosthenes(limit_q);
    int count = 0;
    
    for (size_t i = 0; i < prime_numbers.size(); ++i) {
        long long q = prime_numbers[i];
        long long q_cubed = q * q * q;
        if (q_cubed > n) {
            break;
        }
        for (size_t j = 0; j < i; ++j) {
            long long p = prime_numbers[j];
            if (p * q_cubed <= n) {
                ++count;
            } else {
                break;
            }
        }
    }
    
    return count;
}

int main() {
    long long n;
    cin >> n;
    
    int result = count_super_beautiful_numbers(n);
    cout << result;
    return 0;
}
