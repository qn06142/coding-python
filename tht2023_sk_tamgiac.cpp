#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "../headers/debug.h"
#else
#define debug(...) 42
#endif

bool isPrime[(int) 3e6 + 3];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int i = 2; i <= sqrt(3e6); i++) if(!isPrime[i]){
        for(int j = i * i; j <= (int) 3e6; j += i) {
            isPrime[j] = 1;
        }
    }

    vector<int> prime;
    for(int i = 3; i <= (int) 3e6; i++) if(!isPrime[i]) prime.push_back(i);

    int ntest; cin >> ntest;

    while(ntest--) {
        int n; cin >> n;

        long long ans = (long long) n * (n - 1) * (n - 2) / 6;

        long long sum = 0;

        int p = 0;
        for(int i = 1; i <= n; i++) {
            int u = lower_bound(prime.begin(), prime.end(), 2 * i) - prime.begin();
            int v = upper_bound(prime.begin(), prime.end(), n + i) - prime.begin() - 1;
            if(v >= u) {
                sum += (v - u + 1) * (n - 2);
            }
        }
        ans -= sum;

        for(int i = 1; i <= n; i++) {
            int u = lower_bound(prime.begin(), prime.end(), 2 * i) - prime.begin();
            int v = upper_bound(prime.begin(), prime.end(), n + i) - prime.begin() - 1;
            if(v >= u) {
                int cnt = v - u + 1;
                ans += (cnt * (cnt - 1)) / 2;
            }

            int x = lower_bound(prime.begin(), prime.end(), 2 * i) - prime.begin() - 1;
            int y = lower_bound(prime.begin(), prime.end(), 1 + i) - prime.begin();

            if(x >= y) {
                ans += (x - y + 1) * (v - u + 1);

                int cnt = x - y + 1;

                ans += (cnt * (cnt - 1)) / 2;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}