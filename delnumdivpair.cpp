#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 5;
long long n, cnt[maxn], max_, dp[maxn], res;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        cnt[tmp]++;
        max_ = max(max_, tmp);
    }

    for (int i = max_; i >= 1; i--) {
        for (int j = i; j <= max_; j += i) {
            dp[i] = max(dp[i], dp[j] + cnt[i]);
        }
        res = max(res, dp[i]);
    }
    cout << n - res;
}
