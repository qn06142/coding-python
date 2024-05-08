#include <vector>
#include <algorithm>
#include<iostream>
#include<numeric>
using namespace std;
long long a[(long long) 1e5];
long long max_gift_value(long long n, long long k) {
    long long max_value = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = i + 1; j < n; ++j) {
            if (*max_element(a + 1 + i, a + 1 + j + 1) - *min_element(a + 1 + i, a + 1 + j + 1) <= k) {
                for (long long p = j + 1; p < n; ++p) {
                    for (long long q = p + 1; q < n; ++q) {
                        if (*max_element(a + 1 + p, a + 1  + q + 1) - *min_element(a + 1 + p, a + 1 + q + 1) <= k) {
                            long long gift_sum_i_j = accumulate(a + 1 + i, a + 1 + j + 1, 0);
                            long long gift_sum_p_q = accumulate(a + 1 + p, a + 1 + q + 1, 0);
                            max_value = max(max_value, gift_sum_i_j + gift_sum_p_q);
                        }
                    }
                }
            }
        }
    }
    return max_value;
}

int main() {
    long long n, k;
    cin >> n >> k;
    for(long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << max_gift_value(n, k);

    return 0;
}
