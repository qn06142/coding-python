#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG_INF = LLONG_MIN / 4;

// Segment tree supporting point-update and range-max over [0..k-1]
struct SegMax {
    int n;
    vector<ll> st;
    SegMax(int k) {
        n = 1;
        while (n < k) n <<= 1;
        st.assign(2*n, NEG_INF);
    }
    // set position p to value v
    void update(int p, ll v) {
        p += n;
        st[p] = v;
        for (p >>= 1; p > 0; p >>= 1) {
            st[p] = max(st[2*p], st[2*p+1]);
        }
    }
    // query max over all
    ll query_max() const {
        return st[1];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> t(n+1);
    for(int i = 1; i <= n; i++){
        cin >> t[i];
        --t[i]; // to 0-based
    }
    vector<ll> a(n+1), T(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        T[i] = T[i-1] + a[i];
    }

    // best0: max sum on segment missing at least one type
    vector<vector<int>> pos(k);
    for(int j = 0; j < k; j++) pos[j].push_back(0);
    for(int i = 1; i <= n; i++) pos[t[i]].push_back(i);
    for(int j = 0; j < k; j++) pos[j].push_back(n+1);
    ll best0 = 0;
    for(int j = 0; j < k; j++){
        auto &v = pos[j];
        for(int i = 0; i + 1 < v.size(); i++){
            int L = v[i] + 1;
            int R = v[i+1] - 1;
            if(L <= R) best0 = max(best0, T[R] - T[L-1]);
        }
    }

    // best_cover: using H_j and V_j
    SegMax seg(k);
    vector<ll> H(k, NEG_INF), P(k, 0);
    // initialize H_j(0)=0, so V_j(0)=H_j - k*P_j=0
    for(int j = 0; j < k; j++) seg.update(j, 0);
    
    ll best_cover = NEG_INF;
    for(int i = 1; i <= n; i++){
        int ty = t[i];
        ll prevP = P[ty];
        ll prevT = T[i-1];
        // update prefix sum of type ty
        P[ty] += a[i];
        // query current max V_j = max(H_j - k*P_j(i))
        ll Vmax = seg.query_max();
        // candidate covers subtracting k * x_j (min chosen)
        ll cand = T[i] + Vmax;
        best_cover = max(best_cover, cand);
        // update H_ty = max(H_ty, k*prevP - prevT)
        H[ty] = max(H[ty], (ll)k * prevP - prevT);
        // recompute V_ty = H_ty - k*P_ty
        ll Vnew = H[ty] - (ll)k * P[ty];
        seg.update(ty, Vnew);
    }

    cout << max(best0, best_cover) << "\n";
    return 0;
}
