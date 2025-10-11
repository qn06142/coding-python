#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Query {
    int l, r, w;
    int low, high;  
};

struct Node {
    int pref, suff, best, len;
    Node(int _len=1): pref(0), suff(0), best(0), len(_len) {}
};

vector<Node> seg;
int n;

Node merge_node(const Node &L, const Node &R) {
    Node res;
    res.len  = L.len + R.len;
    res.pref = (L.pref == L.len ? L.len + R.pref : L.pref);
    res.suff = (R.suff == R.len ? R.len + L.suff : R.suff);
    res.best = max({L.best, R.best, L.suff + R.pref});
    return res;
}

void seg_build(int p, int l, int r) {
    if (l == r) {
        seg[p] = Node(1);  
        return;
    }
    int m = (l + r) >> 1;
    seg_build(p<<1,   l,   m);
    seg_build(p<<1|1, m+1, r);
    seg[p] = merge_node(seg[p<<1], seg[p<<1|1]);
}

void seg_update(int p, int l, int r, int pos) {
    if (l == r) {
        seg[p].pref = seg[p].suff = seg[p].best = 1;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m) seg_update(p<<1,   l,   m, pos);
    else         seg_update(p<<1|1, m+1, r, pos);
    seg[p] = merge_node(seg[p<<1], seg[p<<1|1]);
}

Node seg_query(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) return seg[p];
    int m = (l + r) >> 1;
    if (R <= m) return seg_query(p<<1,   l,   m, L, R);
    if (L >  m) return seg_query(p<<1|1, m+1, r, L, R);
    auto left  = seg_query(p<<1,   l,   m, L, R);
    auto right = seg_query(p<<1|1, m+1, r, L, R);
    return merge_node(left, right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    cin >> m;
    vector<Query> Q(m);
    for(int i = 0; i < m; i++){
        int l, r, w;
        cin >> l >> r >> w;
        --l; --r;
        Q[i] = {l, r, w, 0, 0};
    }

    vector<ll> H = h;
    sort(H.begin(), H.end(), greater<ll>());
    H.erase(unique(H.begin(), H.end()), H.end());
    int K = H.size();

    vector<int> rank_of(n);
    {
        unordered_map<ll,int> mp;
        for(int i = 0; i < K; i++) mp[ H[i] ] = i;
        for(int i = 0; i < n; i++) rank_of[i] = mp[h[i]];
    }

    vector<vector<int>> positions_by_rank(K);
    for(int i = 0; i < n; i++){
        positions_by_rank[ rank_of[i] ].push_back(i);
    }

    for(auto &q : Q){
        q.low = 0; 
        q.high = K-1;
    }

    seg.assign(4*n, Node());

    bool changed = true;
    vector<vector<int>> bucket;  
    bucket.reserve(K);
    while(changed) {
        changed = false;

        bucket.assign(K, {});
        for(int i = 0; i < m; i++){
            if (Q[i].low < Q[i].high) {
                int mid = (Q[i].low + Q[i].high) >> 1;
                bucket[mid].push_back(i);
                changed = true;
            }
        }
        if (!changed) break;

        seg_build(1, 0, n-1);

        int p = 0;

        for(int mid = 0; mid < K; mid++){
            while(p <= mid){
                for(int idx: positions_by_rank[p]){
                    seg_update(1, 0, n-1, idx);
                }
                p++;
            }

            for(int qi: bucket[mid]){
                auto &q = Q[qi];
                Node res = seg_query(1, 0, n-1, q.l, q.r);
                if (res.best >= q.w) {

                    q.high = mid;
                } else {
                    q.low = mid + 1;
                }
            }
        }
    }

    ostringstream out;
    for(int i = 0; i < m; i++){
        out << H[ Q[i].low ] << "\n";
    }
    cout << out.str();
    return 0;
}