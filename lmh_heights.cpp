#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 5;
int d[maxn];
int val_rel[maxn]; // relative height compared to its dependency
int val_dep[maxn]; // index of the element that it is depending on for the max
vector<int> adj[maxn];
int ans[maxn];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, h;
    cin >> n >> k >> h;
    for(int i = 2; i <= n; i++) {
    cin >> d[i];
    }
    pair<int, int> curmax = make_pair(0, 1);
    for(int i = 2; i < k; i++) {
    val_rel[i] = d[i] + curmax.first;
    val_dep[i] = curmax.second;
    curmax = max(curmax, make_pair(val_rel[i], i));
    }
    for(int i = 2; i < k; i++) {
        adj[val_dep[i]].push_back(i);
    }

    const long long UNSET = LLONG_MIN / 4;
    for (int i = 1; i <= n; ++i) ans[i] = UNSET;

    queue<pair<int, int>> q;
    q.push(make_pair(h - d[k], curmax.second));
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int idx = cur.second;
        long long val = cur.first;
        if(ans[idx] == UNSET) {
            ans[idx] = val;
        } else if(ans[idx] != val) {
            return 1;
        }

        if (idx >= 2 && idx < k) {
            int p = val_dep[idx]; 
            long long pval = val - d[idx];
            if (ans[p] == UNSET) q.push({pval, p});
            else if (ans[p] != pval) return 1;
        }

        for (int child : adj[idx]) {
            q.push({val + d[child], child });
        }
    }
    ans[k] = h;

    long long max_ = ans[k];
    for (int i = 1; i < k; ++i) {
        if (ans[i] > max_) max_ = ans[i];
    }
    for (int i = k+1; i <= n; ++i) {
        ans[i] = max_ + d[i];
        if (ans[i] > max_) max_ = ans[i];
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

}