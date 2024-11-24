#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 9;
const int MAXN = 1e5 + 5;

int dp[MAXN], pref[MAXN], a[MAXN];
int bit[MAXN];

void update(int i, int v) {
    while (i < MAXN) {
        bit[i] = (bit[i] + v) % MOD;
        i += (i & -i);
    }
}

int getmax(int i) {
    int ans = 0;
    while (i > 0) {
        ans = (ans + bit[i]) % MOD;
        i -= (i & -i);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    map<int, int> compressed;
    vector<int> unique_prefixes;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        unique_prefixes.push_back(pref[i]);
    }
    unique_prefixes.push_back(0); 

    sort(unique_prefixes.begin(), unique_prefixes.end());
    unique_prefixes.erase(unique(unique_prefixes.begin(), unique_prefixes.end()), unique_prefixes.end());
    for (int i = 0; i < unique_prefixes.size(); i++) {
        compressed[unique_prefixes[i]] = i + 1; 
    }

    dp[0] = 1;
    update(compressed[0], dp[0]); 

    for (int i = 1; i <= n; i++) {
        int prefix_index = compressed[pref[i]];
        dp[i] = getmax(prefix_index);

        update(prefix_index, dp[i]); 
    }

    cout << dp[n] << endl;

    return 0;
}