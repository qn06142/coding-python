
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
using ll = long long;

struct FastFenwick {
    int n;
    vector<int> bit;
    FastFenwick() : n(0) {}
    FastFenwick(int n_) { init(n_); }
    void init(int n_) { n = n_; bit.assign(n+1, 0); }
    inline void add(int i, int delta){
        for(; i<=n; i += i & -i) bit[i] += delta;
    }
    inline int sum(int i){
        int r = 0;
        for(; i>0; i -= i & -i) r += bit[i];
        return r;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin >> N)) return 0;
    vector<int> a(N+1);
    for(int i=1;i<=N;i++) cin >> a[i];

    vector<int> vals(a.begin()+1, a.end());
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int M = (int)vals.size();
    vector<vector<int>> pos(M);
    pos.assign(M, {});
    for(int i=1;i<=N;i++){
        int id = int(lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin());
        pos[id].push_back(i);
    }

    ll total = (ll)N * (N + 1) / 2;
    ll bad = 0;

    const int T = 700;
    int Ssize = 2 * N + 5;
    FastFenwick fw(Ssize);

    for(int val = 0; val < M; ++val){
        const auto &pv = pos[val];
        if((int)pv.size() <= T) continue;

        fw.bit.assign(Ssize+1, 0); 

        int S = 0;
        int id = S + N + 1;

        fw.add(id, 1);
        for(int i=1;i<=N;i++){
            if(a[i] == vals[val]) ++S; else --S;
            id = S + N + 1;

            bad += fw.sum(id - 1);
            fw.add(id, 1);
        }
    }

    for(int val = 0; val < M; ++val){
        const auto &p = pos[val];
        int m = (int)p.size();
        if(m == 0 || m > T) continue;

        vector<int> pv;
        pv.reserve(m + 2);
        pv.push_back(0);
        for(int x : p) pv.push_back(x);
        pv.push_back(N + 1);

        for(int k = 1; k <= m; ++k){
            int c = 2*k - 2;
            for(int i = 1; i + k - 1 <= m; ++i){
                int L1 = pv[i-1] + 1;
                int L2 = pv[i];
                int R1 = pv[i+k-1];
                int R2 = pv[i+k] - 1;
                if(L1 > L2 || R1 > R2) continue;

                int l_start = max(L1, R1 - c);
                if(l_start > L2) continue;

                int mid = min(L2, R2 - c);

                ll contrib = 0;
                if(mid >= l_start){

                    ll n1 = (ll)mid - l_start + 1;
                    ll sum_l = ( (ll)l_start + mid ) * n1 / 2;
                    ll add_const = (ll)(c - R1 + 1) * n1;
                    contrib += sum_l + add_const;
                }

                if(mid < L2){
                    int start2 = max(l_start, mid + 1);
                    if(start2 <= L2){
                        ll n2 = (ll)L2 - start2 + 1;
                        ll const_val = (ll)R2 - R1 + 1;
                        if(const_val > 0) contrib += n2 * const_val;
                    }
                }
                bad += contrib;
            }
        }
    }

    cout << (total - bad) << '\n';
}