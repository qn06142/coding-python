#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 100000;
vector<int> adj[MAXN+1];
bool removed[MAXN+1];
int sz[MAXN+1];
char ans[MAXN+1];

int dfs_size(int u, int p){
    sz[u] = 1;
    for(int v : adj[u]) if(v != p && !removed[v]){
        sz[u] += dfs_size(v, u);
    }
    return sz[u];
}

int find_centroid(int u, int p, int total){
    for(int v : adj[u]){
        if(v != p && !removed[v] && sz[v] > total/2)
            return find_centroid(v, u, total);
    }
    return u;
}

void decompose(int u, int p, int depth){
    int total = dfs_size(u, -1);
    int cent = find_centroid(u, -1, total);
    removed[cent] = true;
    if(depth >= 26){

        cout << "Hetcuu!\n";
        exit(0);
    }
    ans[cent] = char('A' + depth);
    for(int v : adj[cent]){
        if(!removed[v]){
            decompose(v, cent, depth+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int max_levels = ceil(log2(n + 1));
    if(max_levels > 26){
        cout << "Impossible!\n";
        return 0;
    }

    decompose(1, -1, 0);

    for(int i = 1; i <= n; i++){
        cout << ans[i] << (i==n? '\n' : ' ');
    }
    return 0;
}