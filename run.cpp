#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> U(M), V(M);
    for(int i = 0; i < M; i++){
        cin >> U[i] >> V[i];
    }

    // Precompute 3^i % MOD
    vector<int> p3(M);
    if(M>0){
        p3[0] = 1;
        for(int i = 1; i < M; i++){
            p3[i] = int((long long)p3[i-1] * 3 % MOD);
        }
    }

    // alive[e] = whether edge e is currently in the graph
    vector<bool> alive(M, true);
    long long answer = 0;

    // adjacency list of edge‐indices for quick rebuild
    vector<vector<int>> adj(N);
    auto rebuild_adj = [&](){
        for(int i = 0; i < N; i++) adj[i].clear();
        for(int e = 0; e < M; e++){
            if(alive[e]){
                adj[U[e]].push_back(e);
                adj[V[e]].push_back(e);
            }
        }
    };

    // BFS check s-t connectivity
    vector<char> seen(N);
    auto connected = [&](){
        fill(seen.begin(), seen.end(), 0);
        deque<int> dq;
        seen[0] = 1;
        dq.push_back(0);
        while(!dq.empty()){
            int u = dq.front(); dq.pop_front();
            if(u == N-1) return true;
            for(int e: adj[u]){
                int w = U[e] ^ V[e] ^ u;  // the other endpoint
                if(!seen[w]){
                    seen[w] = 1;
                    dq.push_back(w);
                }
            }
        }
        return false;
    };

    // Process bits from high to low
    // We will *temporarily* remove edges >= i to test,
    // then decide and possibly *permanently* remove edges == i.
    vector<bool> backup(M);
    for(int i = M-1; i >= 0; --i){
        // 1) temporarily remove all e with index >= i
        for(int e = i; e < M; e++){
            backup[e] = alive[e];
            alive[e] = false;
        }
        rebuild_adj();

        // 2) test connectivity
        if(!connected()){
            // we *must* include 3^i in the cut
            answer = (answer + p3[i]) % MOD;
            // permanently remove edges of index == i (they cross the cut)
            // (they're already removed)
        } else {
            // restore edges index >= i, but we'll handle i-1 next
            for(int e = i; e < M; e++){
                alive[e] = backup[e];
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
