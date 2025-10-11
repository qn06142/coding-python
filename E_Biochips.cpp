#include <bits/stdc++.h>
using namespace std;
const int NEG = INT_MIN/4;

int N, M;
vector<vector<int>> g;
vector<int> mem;
vector<int> tin, tout;
int timer = 0;

void dfs(int u) {
    tin[u] = ++timer;
    for (int v : g[u]) dfs(v);
    tout[u] = timer;
}

struct Node {
    int id;
    int l, r; 
    int w;    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    g.assign(N, {});
    mem.resize(N);
    vector<int> parent(N,-1), roots;
    for (int i=0;i<N;i++) {
        int p,x; cin >> p >> x;
        mem[i]=x;
        if(p==0) roots.push_back(i);
        else { p--; g[p].push_back(i); parent[i]=p; }
    }

    tin.resize(N); tout.resize(N);
    for(int r:roots) dfs(r);

    vector<Node> nodes(N);
    for(int i=0;i<N;i++) nodes[i] = {i, tin[i], tout[i], mem[i]};
    sort(nodes.begin(), nodes.end(), [](auto &a, auto &b){
        return a.r < b.r;
    });

    vector<int> prev(N);
    vector<int> ends(N);
    for(int i=0;i<N;i++) ends[i]=nodes[i].r;
    for(int i=0;i<N;i++){
        int L = nodes[i].l;
        int j = int(upper_bound(ends.begin(), ends.end(), L-1) - ends.begin()) - 1;
        prev[i] = j; 
    }

    vector<vector<int>> dp(M+1, vector<int>(N, NEG));

    for(int i=0;i<N;i++) dp[0][i]=0;

    for(int i=0;i<N;i++){
        for(int k=1;k<=M;k++){

            dp[k][i] = (i>0 ? dp[k][i-1] : NEG);

            int cand = (nodes[i].w) + (prev[i]>=0 ? dp[k-1][prev[i]] : (k==1?0:NEG));
            dp[k][i] = max(dp[k][i], cand);
        }
    }

    cout << dp[M][N-1] << "\n";
}