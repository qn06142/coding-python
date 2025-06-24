#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAXN = 100000;

// make a canonical key u<v
inline ll edge_key(int u, int v) {
    if (u > v) swap(u, v);
    return ll(u) * (MAXN + 1) + v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    unordered_map<ll,int> color;       // 0=black,1=green,2=red
    unordered_set<ll> present;         // which edges are already in the graph
    color.reserve((n+m)*2);
    present.reserve((n+m)*2);

    // read the n boundary edges + m diagonals
    for(int i = 0; i < n + m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ll k = edge_key(u, v);
        present.insert(k);
        color[k] = 0;
    }

    // queue all degree-2 vertices (ear candidates)
    queue<int> q;
    vector<bool> in_queue(n+1,false);
    for(int u = 1; u <= n; ++u){
        if(adj[u].size() == 2){
            q.push(u);
            in_queue[u] = true;
        }
    }

    // helper to remove v from adj[u] in O(deg u)
    auto remove_edge = [&](int u, int v){
        auto &A = adj[u];
        for(size_t i = 0; i < A.size(); ++i){
            if(A[i] == v){
                A[i] = A.back();
                A.pop_back();
                return;
            }
        }
    };

    // ear-peeling: peel off all non-hull vertices
    while(!q.empty()){
        int u = q.front(); q.pop();
        in_queue[u] = false;
        if(adj[u].size() != 2) continue;

        int a = adj[u][0], b = adj[u][1];

        // color (u,a) and (u,b) green if still black
        ll ka = edge_key(u,a);
        if(color[ka] == 0) color[ka] = 1;
        ll kb = edge_key(u,b);
        if(color[kb] == 0) color[kb] = 1;

        // add the a–b diagonal in red, but only if it's truly missing
        ll kab = edge_key(a,b);
        if(!present.count(kab)){
            adj[a].push_back(b);
            adj[b].push_back(a);
            present.insert(kab);
            color[kab] = 2;
        }

        // remove u from its two neighbors
        remove_edge(a, u);
        remove_edge(b, u);

        // **new**: clear u's own adjacency so it doesn't pollute the final cycle
        adj[u].clear();

        // re-enqueue any neighbor that just became degree-2
        if(adj[a].size() == 2 && !in_queue[a]){
            q.push(a);
            in_queue[a] = true;
        }
        if(adj[b].size() == 2 && !in_queue[b]){
            q.push(b);
            in_queue[b] = true;
        }
    }

    // find the smallest‐labeled vertex still on the hull
    int start = 1;
    while(start <= n && adj[start].empty())
        ++start;

    // traverse the green cycle from `start`
    vector<int> seq;
    seq.reserve(n);
    int cur = start, prev = -1;
    do {
        seq.push_back(cur);
        int nxt = -1;
        for(int v : adj[cur]){
            if(v == prev) continue;
            if(color[edge_key(cur, v)] == 1){
                nxt = v;
                break;
            }
        }
        prev = cur;
        cur = nxt;
    } while(cur != start && cur != -1);

    int sz = seq.size();
    // build the reversed‐direction sequence (anchored at same start)
    vector<int> rev(sz);
    for(int i = 0; i < sz; ++i){
        rev[i] = seq[(sz - i) % sz];
    }

    // choose the lexicographically smaller
    if(rev < seq)
        seq.swap(rev);

    // output
    for(int i = 0; i < sz; ++i){
        cout << seq[i] << (i+1 < sz ? ' ' : '\n');
    }

    return 0;
}
