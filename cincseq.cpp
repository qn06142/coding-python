#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 100005;

int n;
vector<int> a, compressed;
int fenwick[MAXN];

void update(int idx, int val) {
    while (idx < MAXN) {
        fenwick[idx] = (fenwick[idx] + val) % MOD;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum = (sum + fenwick[idx]) % MOD;
        idx -= idx & -idx;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    compressed = a;
    sort(compressed.begin(), compressed.end());
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());

    long long result = 0;
    for (int i = 0; i < n; i++) {
        int val = lower_bound(compressed.begin(), compressed.end(), a[i]) - compressed.begin() + 1;
        int dp = (1 + query(val - 1)) % MOD; 
        update(val, dp); 
        result = (result + dp) % MOD; 
    }

    cout << result << "\n";
    return 0;
}