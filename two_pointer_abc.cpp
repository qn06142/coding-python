#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, int> cnt;
    int zero_cnt = 0, unique_cnt = 0, l = 0, res = n + 1;

    for (int r = 0; r < n; r++) {
        if (a[r] == 0) zero_cnt++;
        else if (++cnt[a[r]] == 1) unique_cnt++;

        while (unique_cnt + zero_cnt >= k) {
            res = min(res, r - l + 1);
            if (a[l] == 0) zero_cnt--;
            else if (--cnt[a[l]] == 0) unique_cnt--;
            l++;
        }
    }

    cout << (res == n + 1 ? -1 : res) << '\n';
    return 0;
}
