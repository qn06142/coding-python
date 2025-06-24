#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll count_parity(ll L, ll R, int p) {
    if (L > R) return 0;
    ll len = R - L + 1;

    ll half = len / 2;
    return half + ((len & 1) && ((L & 1) == p) ? 1 : 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    int x, y;
    cin >> n >> x >> y;

    ll c = llabs(y - x);           
    ll s = ll(x) + ll(y);          
    ll b = min(s - 2, 2*n - s);    

    ll A1 = c + 2,   B1 = 2*n - c;      
    ll A2 = s,       B2 = 2*n + 2 - s;  

    struct Seg { ll L, R; ll M; };
    vector<Seg> segs;

    auto add = [&](ll L, ll R, ll M){
        if (L <= R) segs.push_back({L,R,M});
    };

    add(A1, min(B1, A2-1), c);

    add(A2, min(B2, A1-1), b);

    ll L12 = max(A1,A2), R12 = min(B1,B2);
    add(L12, R12, max(c,b));

    add(max(A1, B2+1), B1, c);

    add(max(A2, B1+1), B2, b);

    ll total = 0;
    for (auto &sg : segs) {
        ll L = max<ll>(2, sg.L);
        ll R = min<ll>(2*n, sg.R);
        if (L > R) continue;

        ll len = R - L + 1;
        ll M   = sg.M; 
        int p  = M & 1; 

        ll sum_seg = M * len
                   + count_parity(L, R, p);
        total += sum_seg;
    }

    cout << total << "\n";
    return 0;
}