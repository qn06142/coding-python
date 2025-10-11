#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> deg(n+1, 0);
    vector<vector<int>> adj(n+1);

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; 
        deg[v]++;
    }

    vector<int> leaves;
    leaves.reserve(n);
    for(int i = 1; i <= n; i++){
        if(deg[i] <= 1)
            leaves.push_back(i);
    }

    int L = leaves.size();

    if(L <= 1){
        cout << 0 << "\n";
        return 0;
    }

    int K = (L + 1) / 2;
    cout << K << "\n";

    for(int i = 0; i < K; i++){
        int u = leaves[i];
        int v = leaves[(i + K) % L];
        cout << u << " " << v << "\n";
    }
}