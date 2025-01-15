#include <iostream>
using namespace std;
#pragma GCC optimize("trapv")
#define int long long
int find_mth_number(long long N, long long K, long long M) {
    long long count_per_segment = N / K;

    for (long long remainder = 0; remainder < K; ++remainder) {
        if (M <= count_per_segment) {
            return remainder + K * (M - 1);
        }
        M -= count_per_segment;
    }

    return -1;
}

signed main() {
    long long N, K, M;
    cin >> N >> K >> M;
    cout << find_mth_number(N, K, M) << endl;
    return 0;
}
