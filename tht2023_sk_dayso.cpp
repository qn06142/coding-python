#include <bits/stdc++.h>
using namespace std;

void max_sum_subarray(long long n, long long L, long long R, vector<long long> arr) {
    vector<long long> pre(n);
    multiset<long long> s1;

    // calculating prefix sum
    pre[0] = arr[0];
    for (long long i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + arr[i];
    }

    s1.insert(0);
    long long ans = LONG_LONG_MIN;

    ans = max(ans, pre[L - 1]);

    // we maintain flag to
    // counter if that initial
    // 0 was erased from set or not.
    long long flag = 0;

    for (long long i = L; i < n; i++) {

        // erase 0 from multiset once i=b
        if (i - R >= 0) {
            if (flag == 0) {
                s1.erase(s1.find(0));
                flag = 1;
            }
        }

        // insert pre[i-L]
        if (i - L >= 0) {
            s1.insert(pre[i - L]);
        }

        // find minimum value in multiset.
        ans = max(ans, pre[i] - *s1.begin());

        // erase pre[i-R]
        if (i - R >= 0) {
            s1.erase(s1.find(pre[i - R]));
        }
    }

    cout << ans << endl;
}

int main() {
    //freopen("tht2023_sk_tamgiac.inp", "r", stdin);
    long long n, L, R;
    cin >> n >> L >> R;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    max_sum_subarray(n, L, R, arr);
    return 0;
}
