#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)9e18;

struct SegTree {
    int n;
    vector<ll> st;
    SegTree(int _n=0){ init(_n); }
    void init(int _n){
        n = _n;
        st.assign(4*n+5, INF);
    }
    void point_set(int idx, ll val){ point_set(1,1,n,idx,val); }
    void point_set(int node, int l, int r, int idx, ll val){
        if(l==r){ st[node]=val; return; }
        int m=(l+r)>>1;
        if(idx<=m) point_set(node<<1,l,m,idx,val);
        else point_set(node<<1|1,m+1,r,idx,val);
        st[node] = min(st[node<<1], st[node<<1|1]);
    }
    ll range_min(int L, int R){ if(L>R) return INF; return range_min(1,1,n,L,R); }
    ll range_min(int node, int l, int r, int L, int R){
        if(L<=l && r<=R) return st[node];
        int m=(l+r)>>1;
        ll ans=INF;
        if(L<=m) ans = min(ans, range_min(node<<1,l,m,L,R));
        if(R> m) ans = min(ans, range_min(node<<1|1,m+1,r,L,R));
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,Q;
    int A,B;
    if(!(cin>>N>>Q>>A>>B)) return 0;
    vector<int> x(Q+1);
    for(int i=1;i<=Q;i++) cin>>x[i];

    vector<ll> dp_base(N+1, INF);
    SegTree seg_minus, seg_plus;
    seg_minus.init(N);
    seg_plus.init(N);

    auto set_dp = [&](int pos, ll value_base){
        if(value_base >= INF) return;
        if(value_base < dp_base[pos]){
            dp_base[pos] = value_base;
            seg_minus.point_set(pos, dp_base[pos] - pos);
            seg_plus.point_set(pos, dp_base[pos] + pos);
        }
    };

    if(Q>=1){
        set_dp(A, llabs((ll)B - x[1])); // moved B -> x1, other at A
        set_dp(B, llabs((ll)A - x[1])); // moved A -> x1, other at B
    }

    ll shift = 0;
    for(int i=1;i<=Q-1;i++){
        int cur = x[i];
        int nxt = x[i+1];
        ll d = llabs((ll)nxt - cur);

        // === IMPORTANT: compute candidate (using OLD dp_base and OLD shift) FIRST ===
        ll best1 = seg_minus.range_min(1, nxt);
        if(best1 < INF) best1 += nxt; // X + min(dp[p]-p)
        ll best2 = seg_plus.range_min(nxt, N);
        if(best2 < INF) best2 -= nxt; // -X + min(dp[p]+p)
        ll candidate_base = min(best1, best2); // this is cand0 = min_p(dp_base[p] + |nxt-p|)

        // Now apply shift for the branch "move cur -> nxt"
        shift += d;

        // And when moving the other piece, we must store dp_base'[cur] = cand0 - d
        if(candidate_base < INF){
            ll store = candidate_base - d; // candidate_real - new_shift
            set_dp(cur, store);
        }
    }

    ll min_base = INF;
    for(int p=1;p<=N;p++) if(dp_base[p] < min_base) min_base = dp_base[p];
    ll ans = (min_base>=INF ? INF : shift + min_base);
    cout << ans << '\n';
    return 0;
}
