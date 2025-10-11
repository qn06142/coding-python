#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;

static const int MAXN = 500000;
int n, m;
vector<int> adj[MAXN+1];
int tin[MAXN+1], tout[MAXN+1], dept[MAXN+1];
char ch[MAXN+1];
int timer = 0;

vector<int> td[MAXN+2];
vector<uint> pd[MAXN+2];

void dfs(int u, int d) {
    dept[u] = d;
    tin[u] = timer++;
    for (int v : adj[u]) {
        dfs(v, d+1);
    }
    tout[u] = timer-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        cin >> ch[i];
    }

    dfs(1, 1);

    for(int u = 1; u <= n; u++){
        int d = dept[u];
        td[d].push_back(tin[u]);
    }

    vector<vector<int>> nd(n+2);
    for(int u = 1; u <= n; u++){
        nd[ dept[u] ].push_back(u);
    }
    for(int d = 1; d <= n; d++){
        auto &nodes = nd[d];
        if(nodes.empty()) continue;

        sort(nodes.begin(), nodes.end(), [&](int a, int b){
            return tin[a] < tin[b];
        });

        pd[d].resize(nodes.size());
        uint cur = 0;
        for(size_t i = 0; i < nodes.size(); i++){
            cur ^= (1u << (ch[ nodes[i] ] - 'a'));
            pd[d][i] = cur;
        }

        td[d].resize(nodes.size());
        for(size_t i = 0; i < nodes.size(); i++){
            td[d][i] = tin[ nodes[i] ];
        }
    }

    while(m--){
        int v, h;
        cin >> v >> h;

        if(h > n || td[h].empty()){
            cout << "Yes\n";
            continue;
        }
        auto &T = td[h];
        auto &P = pd[h];
        int L = int(lower_bound(T.begin(), T.end(), tin[v]) - T.begin());
        int R = int(upper_bound(T.begin(), T.end(), tout[v]) - T.begin()) - 1;
        if(L > R){
            cout << "Yes\n";
            continue;
        }
        uint mask = P[R] ^ (L>0 ? P[L-1] : 0u);

        if(__builtin_popcount(mask) <= 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}