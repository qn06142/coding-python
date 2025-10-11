#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct tree_solver {
    // Nested BIT (Fenwick) supporting range add / point query
    struct BIT {
        int n;
        vector<ll> f;
        BIT(): n(0) {}
        BIT(int n_){ init(n_); }
        void init(int n_){
            n = n_;
            f.assign(n + 5, 0);
        }
        void add(int i, ll delta){
            // safe bound: iterate while i < f.size()
            for(; i < (int)f.size(); i += i & -i) f[i] += delta;
        }
        ll sum(int i){
            ll r = 0;
            for(; i > 0; i -= i & -i) r += f[i];
            return r;
        }
        void range_add(int l, int r, ll v){
            if(l > r) return;
            add(l, v);
            add(r + 1, -v);
        }
        ll point(int i){ return sum(i); }
    };

    int n, q;
    vector<ll> val;
    vector<vector<int>> g;

    vector<int> tin, tout, parent, it_index;
    vector<ll> pref;
    int timer;
    vector<ll> arr;
    BIT bit;

    tree_solver() : n(0), q(0), timer(0) {}

    void read_input(istream &in = cin){
        if(!(in >> n >> q)) {
            n = q = 0;
            return;
        }
        val.assign(n + 1, 0);
        for(int i = 1; i <= n; ++i) in >> val[i];

        g.assign(n + 1, {});
        for(int i = 0; i < n - 1; ++i){
            int a, b; in >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    void build(){
        if(n == 0) return;

        tin.assign(n + 1, 0);
        tout.assign(n + 1, 0);
        parent.assign(n + 1, 0);
        it_index.assign(n + 1, 0);
        pref.assign(n + 1, 0);
        timer = 0;

        // iterative DFS (stack of pair<u, parent>)
        stack<pair<int,int>> st;
        st.push({1, 0});
        parent[1] = 0;
        while(!st.empty()){
            auto [u, p] = st.top();
            if(it_index[u] == 0){
                parent[u] = p;
                tin[u] = ++timer;
                if(p == 0) pref[u] = val[u];
                else pref[u] = pref[p] + val[u];
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

        // init BIT with safe size (allow indices up to n+2)
        bit.init(n + 5);
        for(int i = 1; i <= n; ++i){
            if(arr[i] != 0) bit.range_add(i, i, arr[i]);
        }
    }

    void process_queries(istream &in = cin, ostream &out = cout){
        for(int qi = 0; qi < q; ++qi){
            int t; in >> t;
            if(t == 1){
                int s; ll x; in >> s >> x;
                ll delta = x - val[s];
                if(delta != 0){
                    bit.range_add(tin[s], tout[s], delta);
                    val[s] = x;
                } else {
                    val[s] = x;
                }
            } else if(t == 2){
                int s; in >> s;
                ll ans = bit.point(tin[s]);
                out << ans << '\n';
            }
        }
    }

    void run(istream &in = cin, ostream &out = cout){
        read_input(in);
        if(n == 0) return;
        build();
        process_queries(in, out);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tree_solver solver;
    solver.run();
    return 0;
}
