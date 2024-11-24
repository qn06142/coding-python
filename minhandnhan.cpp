#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long min_score = LLONG_MAX;
    for (long long mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) == k) {
            vector<long long> Minh, Nhan;
            for (long long i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    Minh.push_back(a[i]);
                } else {
                    Nhan.push_back(a[i]);
                }
            }
            long long score = 0;
            for (long long ai : Minh) {
                for (long long aj : Nhan) {
                    score += abs(ai - aj);
                }
            }
            min_score = min(min_score, score);
        }
    }

    cout << min_score << endl;

    return 0;
}
