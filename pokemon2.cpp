#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    #define int long long
    int N;
    long long M;
    cin >> N >> M;

    vector<long long> a(N), b(N);
    long long max_ = 0;

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        max_ = max(max_, a[i]);
    }

    long long left = max_, right = max_ + M * 1000000, ans = max_;

    auto check = [&](long long target) {
        long long need = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] < target) {
                long long needed = (target - a[i] + b[i] - 1) / b[i];
                need += needed;
                if (need > M) return false;
            }
        }
        return need <= M;
    };

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
