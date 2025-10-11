#include<bits/stdc++.h>
using namespace std;

// what have i done
struct tree_solver {

    struct BIT {
        int n;
        vector<long long> f;
        BIT(): n(0) {}
        BIT(int n_){ init(n_); }
        void init(int n_){
            n = n_;
            f.assign(n + 5, 0);
        }
        void add(int i, long long delta){
            for(; i < (int)f.size(); i += i & -i) f[i] += delta;
        }
        long long sum(int i) const {
            long long r = 0;
            for(; i > 0; i -= i & -i) r += f[i];
            return r;
        }
        void range_add(int l, int r, long long v){
            if(l > r) return;
            add(l, v);
            add(r + 1, -v);
        }
        long long point(int i) const { return sum(i); }
    };

    int n = 0;
    vector<long long> val;            
    vector<vector<int>> g;           

    vector<int> tin, tout, parent;
    vector<int> depth;
    int timer = 0;
    vector<long long> pref;          
    vector<long long> arr;           
    BIT bit;

    int LOG = 0;
    vector<vector<int>> up;

    tree_solver() = default;

    void set_tree(int n_, const vector<long long>& vals, const vector<pair<int,int>>& edges, int root = 1){
        n = n_;
        if((int)vals.size() != n + 1) throw runtime_error("vals must be size n+1 and 1-indexed");
        val = vals;
        g.assign(n + 1, {});
        for(auto &e: edges){
            int a = e.first, b = e.second;
            if(a < 1 || a > n || b < 1 || b > n) throw runtime_error("edge endpoints out of range");
            g[a].push_back(b);
            g[b].push_back(a);
        }
        build(root);
    }

private:

    void build(int root){
        if(n == 0) return;

        tin.assign(n + 1, 0);
        tout.assign(n + 1, 0);
        parent.assign(n + 1, 0);
        depth.assign(n + 1, 0);
        pref.assign(n + 1, 0);
        timer = 0;

        vector<int> it_index(n + 1, 0);
        stack<pair<int,int>> st;
        st.push({root, 0});
        parent[root] = 0;
        while(!st.empty()){
            auto [u, p] = st.top();
            if(it_index[u] == 0){
                parent[u] = p;
                tin[u] = ++timer;
                depth[u] = (p == 0 ? 0 : depth[p] + 1);
                pref[u] = (p == 0 ? val[u] : pref[p] + val[u]);
            }
            if(it_index[u] < (int)g[u].size()){
                int v = g[u][it_index[u]++];
                if(v == p) continue;
                st.push({v, u});
            } else {
                tout[u] = timer;
                st.pop();
            }
        }

        arr.assign(n + 2, 0);
        for(int u = 1; u <= n; ++u) arr[tin[u]] = pref[u];

        bit.init(n + 5);
        for(int i = 1; i <= n; ++i){
            if(arr[i] != 0) bit.range_add(i, i, arr[i]);
        }

        LOG = 1;
        while((1 << LOG) <= n) ++LOG;
        up.assign(LOG, vector<int>(n + 1, 0));
        for(int v = 1; v <= n; ++v) up[0][v] = parent[v];
        for(int k = 1; k < LOG; ++k){
            for(int v = 1; v <= n; ++v){
                int mid = up[k-1][v];
                up[k][v] = (mid == 0 ? 0 : up[k-1][mid]);
            }
        }
    }

    int lca(int a, int b) const {
        if(a == 0 || b == 0) return a ^ b; 
        if(depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for(int k = 0; k < LOG; ++k) if(diff & (1 << k)) a = up[k][a];
        if(a == b) return a;
        for(int k = LOG - 1; k >= 0; --k){
            if(up[k][a] != up[k][b]){
                a = up[k][a];
                b = up[k][b];
            }
        }
        return parent[a];
    }

public:

    void update_node(int s, long long x){
        if(s < 1 || s > n) throw runtime_error("update_node: s out of range");
        long long delta = x - val[s];
        if(delta != 0){

            bit.range_add(tin[s], tout[s], delta);
            val[s] = x;
        } else {
            val[s] = x;
        }
    }

    long long get_pref(int u) const {
        if(u < 1 || u > n) throw runtime_error("get_pref: u out of range");
        return bit.point(tin[u]);
    }

    long long query_path(int u, int v) const {
        if(u < 1 || u > n || v < 1 || v > n) throw runtime_error("query_path: endpoints out of range");
        int L = lca(u, v);
        long long pu = bit.point(tin[u]);
        long long pv = bit.point(tin[v]);
        long long pl = bit.point(tin[L]);

        return pu + pv - 2LL * pl + val[L];
    }
};

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    map<int, vector<int>> cows;
    map<int, vector<pair<pair<int, int>, int>>> queries;
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        cows[t].push_back(i);
    }
    vector<pair<int, int>> edges;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    for(int i = 1; i <= q; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        queries[t].push_back({{u, v}, i});
    }
    cows[0].clear();
    tree_solver ds;
    ds.set_tree(n, vector<long long>(n + 1), edges);
    vector<int> previous = cows[0];
    string ans(q, '0');

    for(auto cur:queries) {
        for(int cow:previous) {
            ds.update_node(cow, 0);
        }
        for(int cow:cows[cur.first]) {
            ds.update_node(cow, 1);
        }
        for(pair<pair<int, int>, int> query : cur.second) {
            long long sum = ds.query_path(query.first.first, query.first.second);
            ans[query.second - 1] = (sum > 0) + '0';
        }
        previous = cows[cur.first];
    }
    cout << ans;
}