#include<bits/stdc++.h>

using namespace std;

long long lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}
#define int long long
int cnt[(int)3e3 + 5], f[(int)3e3 + 5];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        x = x % m;
        cnt[x]++;
    }
    for(int i = 0; i < m; i++) {
        if(i == 0) {
            for(int j = 0; j < m; j++) {
                f[j] += cnt[i];
            }
        } else {
            for(int j = 1; j * j <= i; j++) {
                if(i % j == 0) {
                    f[j] += cnt[i];
                    if(j != i / j) {
                        f[i / j] += cnt[i];
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int a = 0; a < m; a++) { if(cnt[a])
        for(int b = 0; b < m; b++) { if(cnt[b]) {
            int g = __gcd(a * b, m);
            int r = m / g;
            if(r == m) {
                r = 0;
            }
            if(a != 0 and b != 0) {
                ans += cnt[a] * cnt[b] * f[r];
            } else {
                ans += cnt[a] * cnt[b] * n;
            }
            }
        }
    }
    cout << ans;
}