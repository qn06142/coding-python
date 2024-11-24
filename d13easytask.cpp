#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

// Hàm Sàng Eratosthenes để tìm tất cả các số nguyên tố từ 1 đến max_num
vector<int> sieve_of_eratosthenes(int max_num) {
    vector<bool> is_prime(max_num + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 và 1 không phải là số nguyên tố
    for (int p = 2; p * p <= max_num; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= max_num; i += p) {
                is_prime[i] = false;
            }
        }
    }
    vector<int> primes;
    for (int num = 2; num <= max_num; ++num) {
        if (is_prime[num]) {
            primes.push_back(num);
        }
    }
    return primes;
}

// Hàm tìm tổng lớn nhất của đoạn đẹp
int max_beautiful_segment_sum(int n, const vector<int>& a) {
    vector<int> primes = sieve_of_eratosthenes(n);
    vector<long long> prefix_sum(n + 1, 0);

    // Tạo mảng prefix_sum
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    int max_sum = INT_MIN;
    
        for (int R : primes) {
            if (L <= R && R <= n) {
                int segment_sum = prefix_sum[R] - prefix_sum[L - 1];
                if (segment_sum > max_sum) {
                    max_sum = segment_sum;
                }
            }
        }

    return max_sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << max_beautiful_segment_sum(n, a) << endl;
    return 0;
}
