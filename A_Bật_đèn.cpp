#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int a[maxn], l[maxn], r[maxn];
vector<pair<int, int>> graph[maxn];
int col[maxn];

void dfs(int u, int k) {
    col[u] = k;
    
    for (auto pi : graph[u]) {
        int v = pi.first, w = pi.second;
        
        if (col[v] == -1) {
            dfs(v, k ^ (1 - w));
        } else if (col[v] != k ^ (1 - w)) {
            cout << "NO\n";
            exit(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    memset(l, -1, sizeof l);
    
    for (int i = 1; i <= m; ++i) {
        int k;
        cin >> k;
        
        for (int j = 1; j <= k; ++j) {
            int x;
            cin >> x;
            
            if (l[x] == -1) {
                l[x] = i;
            } else {
                r[x] = i;
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        graph[l[i]].emplace_back(r[i], a[i]);
        graph[r[i]].emplace_back(l[i], a[i]);
    }
    
    memset(col, -1, sizeof col);
    
    for (int i = 1; i <= m; ++i) {
        if (col[i] == -1) {
            dfs(i, 0);
        }
    }
    
    cout << "YES\n";
}
