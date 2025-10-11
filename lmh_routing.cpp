#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG_INF = LLONG_MIN / 4;

struct LCT {
    int N;
    struct Node {
        int ch[2];
        int p;
        bool rev;
        ll val;      
        ll maxv;
        int maxid;   
        Node(): p(0), rev(false), val(NEG_INF), maxv(NEG_INF), maxid(0) { ch[0]=ch[1]=0; }
    };
    vector<Node> t;
    LCT(int n=0){ init(n); }
    void init(int n){
        N = n;
        t.assign(N+1, Node());
        for(int i=0;i<=N;i++){
            t[i].maxid = i;
        }
    }
    bool is_root(int x){
        int p = t[x].p;
        if(!p) return true;
        return t[p].ch[0] != x && t[p].ch[1] != x;
    }
    void push_up(int x){
        t[x].maxv = t[x].val;
        t[x].maxid = x;
        for(int k=0;k<2;k++){
            int c = t[x].ch[k];
            if(c){
                if(t[c].maxv > t[x].maxv || (t[c].maxv == t[x].maxv && t[c].maxid > t[x].maxid)){
                    t[x].maxv = t[c].maxv;
                    t[x].maxid = t[c].maxid;
                }
            }
        }
    }
    void push_down(int x){
        if(!x) return;
        if(t[x].rev){
            int l = t[x].ch[0], r = t[x].ch[1];
            if(l) t[l].rev ^= 1, swap(t[l].ch[0], t[l].ch[1]);
            if(r) t[r].rev ^= 1, swap(t[r].ch[0], t[r].ch[1]);
            t[x].rev = false;
        }
    }
    void rotate(int x){
        int p = t[x].p;
        int g = t[p].p;
        int is_right = (t[p].ch[1] == x);
        int b = t[x].ch[is_right^1];
        if(!is_root(p)){
            if(t[g].ch[0]==p) t[g].ch[0]=x; else if(t[g].ch[1]==p) t[g].ch[1]=x;
        }
        t[x].p = g;
        t[x].ch[is_right^1] = p;
        t[p].p = x;
        t[p].ch[is_right] = b;
        if(b) t[b].p = p;
        push_up(p);
        push_up(x);
    }
    void push_all(int x){
        if(!is_root(x)) push_all(t[x].p);
        push_down(x);
    }
    void splay(int x){
        push_all(x);
        while(!is_root(x)){
            int p = t[x].p;
            int g = t[p].p;
            if(!is_root(p)){
                if((t[p].ch[0]==x) ^ (t[g].ch[0]==p)) rotate(x);
                else rotate(p);
            }
            rotate(x);
        }
    }
    int access(int x){
        int last = 0;
        for(int y = x; y; y = t[y].p){
            splay(y);
            t[y].ch[1] = last;
            push_up(y);
            last = y;
        }
        splay(x);
        return last;
    }
    void make_root(int x){
        access(x);
        t[x].rev ^= 1;
        swap(t[x].ch[0], t[x].ch[1]);
    }
    int find_root(int x){
        access(x);
        while(true){
            push_down(x);
            if(t[x].ch[0]) x = t[x].ch[0];
            else break;
        }
        splay(x);
        return x;
    }

    void split(int u, int v){
        make_root(u);
        access(v);

    }
    bool connected(int u, int v){
        if(u==v) return true;
        return find_root(u) == find_root(v);
    }

    bool link(int u, int v){
        make_root(u);
        if(find_root(v) == u) return false; 
        t[u].p = v;
        return true;
    }

    bool cut(int u, int v){
        make_root(u);
        if(find_root(v) != u) return false;
        access(v);

        if(t[v].ch[0] != u) return false;
        t[v].ch[0] = 0;
        t[u].p = 0;
        push_up(v);
        return true;
    }

    void set_val(int x, ll value){
        t[x].val = value;
        push_up(x);
    }

    pair<ll,int> query_max(int u, int v){
        split(u,v);
        return { t[v].maxv, t[v].maxid };
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if(!(cin >> n >> m)) return 0;

    int total = n + m + 5;
    LCT lct(total);

    for(int i=1;i<=n;i++){
        lct.set_val(i, NEG_INF);
    }

    vector<int> eu(total,0), ev(total,0);
    vector<ll> ew(total,0);
    int edge_node_index = n; 
    for(int i=0;i<m;i++){
        int u,v; long long w,s,t;
        cin >> u >> v >> w >> s >> t;

        ++edge_node_index;
        int e = edge_node_index;
        eu[e] = u; ev[e] = v; ew[e] = w;
        lct.set_val(e, w);

        if(!lct.connected(u, v)){

            lct.link(u, e);
            lct.link(e, v);
        } else {

            auto qm = lct.query_max(u, v);
            ll maxw = qm.first;
            int maxid = qm.second;
            if(maxw > w){

                int a = eu[maxid], b = ev[maxid];

                lct.cut(a, maxid);
                lct.cut(maxid, b);

                lct.link(u, e);
                lct.link(e, v);
            } else {

            }
        }

        if(!lct.connected(s, t)){
            cout << -1 << '\n';
        } else {
            auto ans = lct.query_max(s, t);
            cout << ans.first << '\n';
        }
    }
    return 0;
}