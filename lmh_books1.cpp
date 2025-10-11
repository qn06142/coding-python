
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<long long> b(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    int best = 0;

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n - x; y++) {

            unordered_set<int> codes;
            long long cost = 0;
            int cnt = 0;
            bool valid = true;

            for (int i = 1; i <= x; i++) {
                if (codes.count(a[i])) { valid = false; break; }
                codes.insert(a[i]);
                cost += b[i];
                cnt++;
            }
            if (!valid) continue;

            for (int i = n - y + 1; i <= n; i++) {
                if (codes.count(a[i])) { valid = false; break; }
                codes.insert(a[i]);
                cost += b[i];
                cnt++;
            }
            if (!valid) continue;

            if (cost <= m) best = max(best, cnt);
        }
    }

    cout << best << "\n";
    return 0;
}