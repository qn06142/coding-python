#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int u, v;
    ll w;
};

struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n=0): n(n), p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int a){ return p[a]==a ? a : p[a]=find(p[a]); }
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if(a==b) return false;
        if(r[a] < r[b]) swap(a,b);
        p[b] = a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin >> N)) return 0;
    vector<int> xs(N), ys(N);
    const int MAXY = 11; 
    vector<vector<pair<int,int>>> rows(MAXY); 
    for(int i=0;i<N;i++){
        int x,y; cin >> x >> y;
        xs[i]=x; ys[i]=y;
        rows[y].push_back({x,i});
    }
    for(int y=0;y<MAXY;y++){
        sort(rows[y].begin(), rows[y].end()); 
    }

    vector<Edge> edges;
    edges.reserve((size_t)MAXY * MAXY * max(1, N / 2));

    for(int a=0;a<MAXY;a++){

        if(!rows[a].empty()){
            for(size_t i=1;i<rows[a].size();++i){
                int id1 = rows[a][i-1].second;
                int id2 = rows[a][i].second;
                ll dx = ll(xs[id1]) - ll(xs[id2]);
                ll dy = ll(ys[id1]) - ll(ys[id2]);
                edges.push_back({id1, id2, dx*dx + dy*dy});
            }
        }
        for(int b=a+1;b<MAXY;b++){

            size_t ia=0, ib=0;
            int prev_id = -1;
            while(ia < rows[a].size() || ib < rows[b].size()){
                int cur_id;
                if(ib >= rows[b].size() || (ia < rows[a].size() && rows[a][ia].first <= rows[b][ib].first)){
                    cur_id = rows[a][ia++].second;
                } else {
                    cur_id = rows[b][ib++].second;
                }
                if(prev_id != -1 && prev_id != cur_id){
                    ll dx = ll(xs[prev_id]) - ll(xs[cur_id]);
                    ll dy = ll(ys[prev_id]) - ll(ys[cur_id]);
                    edges.push_back({prev_id, cur_id, dx*dx + dy*dy});
                }
                prev_id = cur_id;
            }
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){ return a.w < b.w; });
    DSU dsu(N);
    ll total = 0;
    int used = 0;
    for(const auto &e : edges){
        if(dsu.unite(e.u, e.v)){
            total += e.w;
            if(++used == N-1) break;
        }
    }

    cout << total << '\n';
}