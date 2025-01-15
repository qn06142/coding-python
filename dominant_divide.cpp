#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005; 
int a[maxn];
int dp[maxn];
const int mod = 1e9 + 7;
int main() {
    #ifdef ONLINE_JUDGE
    freopen("DOMI.INP", "r", stdin);
    freopen("DOMI.OUT", "w", stdout);
    #endif
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[0] = 1; 

    for (int i = 1; i <= n; i++) {
        unordered_map<int, int> freq; 
        int max_freq = 0;            

        for (int j = i; j >= 1; j--) {
            freq[a[j]]++;                  
            max_freq = max(max_freq, freq[a[j]]); 

            if (max_freq * 2 <= (i - j + 1)) {
                dp[i] += dp[j - 1]; 
                dp[i] %= mod;
            }
        }
    }

    cout << dp[n] % mod << endl;
    return 0;
}