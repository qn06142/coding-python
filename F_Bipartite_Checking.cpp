#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rnk, parity;
    vector<tuple<int,int,int,int,int>> stk;
    bool bad = false;

    DSU(int n): parent(n+1), rnk(n+1,0), parity(n+1,0) {
        iota(parent.begin(), parent.end(), 0);
    }

    pair<int,int> find(int u) {
        if (parent[u] == u) return {u, 0};
        auto res = find(parent[u]);
        res.second ^= parity[u];
        return res;
    }

    void unite(int u, int v) {
        auto [ru, pu] = find(u);
        auto [rv, pv] = find(v);
        if (ru == rv) {

            if ((pu ^ pv) != 1) {
                stk.emplace_back(-1,-1,-1,-1,-1);
                bad = true;
            } else {
                stk.emplace_back(-2,-2,-2,-2,-2);
            }
            return;
        }

        if (rnk[ru] < rnk[rv]) {
            swap(ru, rv);
            swap(pu, pv);
        }

        stk.emplace_back(ru, rv, rnk[ru], parity[rv], pu ^ pv ^ 1);

        parent[rv] = ru;
        parity[rv] = pu ^ pv ^ 1;
        if (rnk[ru] == rnk[rv]) {
            rnk[ru]++;
        }
    }

    int snapshot() { return stk.size(); }
    void rollback(int snap) {
        while ((int)stk.size() > snap) {
            auto [ru, rv, old_rnk, old_parity_rv, delta] = stk.back();
            stk.pop_back();
            if (ru == -1) {

                bad = false;
            } else if (ru == -2) {

            } else {

                parent[rv] = rv;
                parity[rv] = old_parity_rv;
                rnk[ru] = old_rnk;
            }
        }
    }
};

int n, q;
vector<vector<pair<int,int>>> segtree;  

void add_edge(int id, int l, int r, int ql, int qr, pair<int,int> e){
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr){
        segtree[id].push_back(e);
        return;
    }
    int mid = (l + r) >> 1;
    add_edge(id<<1,    l, mid, ql, qr, e);
    add_edge(id<<1|1, mid+1, r, ql, qr, e);
}

vector<string> answer;
DSU *dsu_ptr;

void dfs(int id, int l, int r) {
    int snap = dsu_ptr->snapshot();

    for (auto &e : segtree[id]) {
        dsu_ptr->unite(e.first, e.second);
    }
    if (l == r) {
        answer[l] = (dsu_ptr->bad ? "NO" : "YES");
    } else {
        int mid = (l + r) >> 1;
        dfs(id<<1,    l, mid);
        dfs(id<<1|1, mid+1, r);
    }
    dsu_ptr->rollback(snap);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    map<pair<int,int>, int> active;
    vector<pair<int,int>> queries(q+1);
    for (int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x,y);
        queries[i] = {x,y};
    }

    segtree.resize(4*(q+5));
    for (int i = 1; i <= q; i++){
        auto e = queries[i];
        if (!active.count(e)) {
            active[e] = i;
        } else {
            int start = active[e];
            add_edge(1, 1, q, start, i-1, e);
            active.erase(e);
        }
    }

    for (auto &it : active) {
        int start = it.second;
        add_edge(1, 1, q, start, q, it.first);
    }

    DSU dsu(n);
    dsu_ptr = &dsu;
    answer.assign(q+1, "");

    dfs(1, 1, q);

    for (int i = 1; i <= q; i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}