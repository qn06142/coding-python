#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> p, r;
    vector<long long> comp_sum;
    multiset<long long> *ms;
    DSU(int n, vector<long long> &w, multiset<long long> *ms_ptr): p(n+1), r(n+1,0), comp_sum(n+1), ms(ms_ptr) {
        for(int i=1;i<=n;i++){
            p[i]=i;
            comp_sum[i]=w[i];
            ms->insert(w[i]);
        }
    }
    int findp(int x) {
        return p[x]==x? x : p[x]=findp(p[x]);
    }
    void unite(int a, int b) {
        int pa = findp(a);
        int pb = findp(b);
        if(pa==pb) return;

        ms->erase(ms->find(comp_sum[pa]));
        ms->erase(ms->find(comp_sum[pb]));

        if(r[pa]<r[pb]) swap(pa,pb);
        p[pb]=pa;
        comp_sum[pa] += comp_sum[pb];
        if(r[pa]==r[pb]) r[pa]++;

        ms->insert(comp_sum[pa]);
    }
    void change_weight(int node, long long old_w, long long new_w) {
        int root = findp(node);

        ms->erase(ms->find(comp_sum[root]));

        comp_sum[root] += (new_w - old_w);

        ms->insert(comp_sum[root]);
    }
};

struct Op {
    char type; 
    int x;
    long long val;  
    long long old;  
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vector<long long> w(n+1);
    for(int i=1;i<=n;i++) cin >> w[i];
    vector<int> u(m+1), v(m+1);
    for(int i=1;i<=m;i++) cin >> u[i] >> v[i];
    vector<Op> ops(q);
    vector<bool> deleted(m+1, false);

    for(int i=0;i<q;i++){
        char t;
        cin >> t;
        ops[i].type = t;
        if(t=='D'){
            cin >> ops[i].val;
            deleted[ops[i].val] = true;
        } else if(t=='C'){
            cin >> ops[i].x >> ops[i].val;
            ops[i].old = w[ops[i].x];
            w[ops[i].x] = ops[i].val;
        }
    }

    multiset<long long> ms;
    DSU dsu(n, w, &ms);
    for(int i=1;i<=m;i++){
        if(!deleted[i]) {
            dsu.unite(u[i], v[i]);
        }
    }

    vector<long long> ans(q);

    for(int i=q-1;i>=0;i--){

        ans[i] = *ms.rbegin();
        if(ops[i].type=='D'){
            int ei = ops[i].val;
            dsu.unite(u[ei], v[ei]);
        } else {
            int node = ops[i].x;
            long long new_w = ops[i].val;
            long long old_w = ops[i].old;

            dsu.change_weight(node, new_w, old_w);
        }
    }

    for(int i=0;i<q;i++){
        cout << ans[i] << '\n';
    }
}