#include<bits/stdc++.h>
#define X first
#define Y second
#define all(x) begin(x), end(x)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

typedef long long ll;
const int N = 1e5 + 7;

const int N = 1e5 + 7;

int n, a[N];
ll dp[N], pre[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    FOR(i, 1, n) {
        cin>>a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    dp[1] = a[1];
    set<pair<long long, int>> set_1;
    multiset<long long> set_2;
    set_1.insert({dp[1] + 1, 1});
    set_2.insert(dp[1] + 1 - pre[1]);
    FOR(i, 2, n) {
        while (!set_1.empty()) {
            pair<long long, int> tmp = *set_1.begin();
            long long value = tmp.X;
            int idx = tmp.Y;
            if (value >= i) break;
            long long delete_value = dp[idx] + idx - pre[idx];
            set_2.erase(set_2.find(delete_value));
            set_1.erase(set_1.begin());
        }
        if (!set_2.empty()) {
            ll opt_value = *set_2.rbegin(); // phan tu  cuoi cung trong set
            dp[i] = opt_value - i + pre[i];
        }
//        exit(0);set_1.insert({dp[i] + i, i});
        set_2.insert(dp[i] + i - pre[i]);
    }
    cout<<*max_element(dp + 1, dp + 1 + n);
    return 0;
}
