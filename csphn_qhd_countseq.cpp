#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int power2(int k) {
    int ans = 1;
    int a = 2;
    while (k > 0) {
        if (k % 2 == 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        k /= 2;
    }
    return ans;
}

vector<int> d;
void calc(int s) {
    d.clear();
    int i;
    for(i = 1; i * i < s; i++) {
        if(s % i == 0) {
            d.push_back(i);
            if(i != s / i)
            d.push_back(s / i);
        }
    }
    if(i * i == s) d.push_back(i);
    sort(d.begin(), d.end());
}
int solve(int S) {

    vector<int> dp(d.size());
    
    for (int i = 0; i < (int) d.size(); i++) {
        int x = d[i];
        dp[i] = power2(x - 1);
        for(int j = 0; j < i; j++) {
            if(x % d[j] == 0) {
                if(x % d[j] == 0) {
                    dp[i] = (dp[i] - dp[j]) % MOD;
                }
            }
        }
    }
    
    return (dp[d.size() - 1] + MOD) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int S;
        cin >> S;
        calc(S);
        cout << solve(S) << '\n';
    }
    
    return 0;
}
