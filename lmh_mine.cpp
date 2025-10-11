#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INFLL = (ll)9e18;

// Fenwick for prefix-min (1-indexed)
struct FenwickMin {
    int n;
    vector<ll> bit;
    FenwickMin(int _n=0){ init(_n); }
    void init(int _n){
        n = _n;
        bit.assign(n+1, INFLL);
    }
    // point "min-update": bit[pos] = min(bit[pos], val), propagate upward
    void update(int pos, ll val){
        for(; pos <= n; pos += pos & -pos)
            if (val < bit[pos]) bit[pos] = val;
    }
    // query min on prefix [1..pos]
    ll query(int pos){
        if(pos <= 0) return INFLL;
        ll res = INFLL;
        for(; pos > 0; pos -= pos & -pos)
            if (bit[pos] < res) res = bit[pos];
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        int n;
        cin >> n;
        vector<ll> x(n+1), g(n+1), r(n+1);
        for(int i=1;i<=n;i++) cin >> x[i] >> g[i] >> r[i];

        // prefix sums SR and PG (1-based)
        vector<ll> SR(n+1,0), PG(n+1,0);
        for(int i=1;i<=n;i++){
            SR[i] = SR[i-1] + r[i];
            PG[i] = PG[i-1] + g[i];
        }

        // prepare A_p = A_{p+1} = x_{p+1} - SR[p] for p=0..n-1
        // and B_j = x_j - SR[j] for j=1..n
        vector<ll> A; A.reserve(n);
        for(int p=0;p<=n-1;p++){
            A.push_back( x[p+1] - SR[p] );
        }
        vector<ll> all = A;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        int m = (int)all.size();

        auto get_id = [&](ll v)->int{
            return int(lower_bound(all.begin(), all.end(), v) - all.begin()) + 1; // 1-based
        };

        // Fenwick on reversed indices so we can query suffix-min as prefix-min
        FenwickMin fw(m);

        // initially update p = 0 (corresponds l=1) with PG[0]=0
        int id0 = get_id(A[0]);
        int rev0 = m - id0 + 1;
        fw.update(rev0, PG[0]);

        ll ans = 0;
        for(int j=1;j<=n;j++){
            ll Bj = x[j] - SR[j];
            // find first index in all with value >= Bj
            int pos = int(lower_bound(all.begin(), all.end(), Bj) - all.begin()) + 1; // 1-based
            if(pos <= m){
                int revq = m - pos + 1;
                ll bestP = fw.query(revq);
                if(bestP != INFLL){
                    ans = max(ans, PG[j] - bestP);
                }
            }
            // update p = j (for future j+1): index corresponds to A_{j+1} = A[p] where p=j
            if(j <= n-1){
                int idp = get_id(A[j]);
                int revp = m - idp + 1;
                fw.update(revp, PG[j]);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
