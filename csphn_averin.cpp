#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> xs = a;
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    int d = xs.size();
    vector<int> comp(n);
    for(int i = 0; i < n; i++){
        comp[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin();
    }

    vector<int> seen(d, 0);
    int timestamp = 0;
    ll ans = 0;

    for(int i = 0; i < n; i++){
        ll sum = 0;
        ++timestamp;

        for(int j = i; j < n; j++){
            sum += a[j];
            seen[comp[j]] = timestamp;
            int len = j - i + 1;
            if (sum % len == 0) {
                int avg = sum / len;

                auto it = lower_bound(xs.begin(), xs.end(), avg);
                if (it != xs.end() && *it == avg) {
                    int idx = it - xs.begin();
                    if (seen[idx] == timestamp) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}