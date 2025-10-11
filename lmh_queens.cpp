#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Q { int r, c, idx; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k;
    int n;
    cin >> k >> n;

    vector<Q> qs(n);
    for (int i = 0; i < n; i++) {
        cin >> qs[i].r >> qs[i].c;
        qs[i].idx = i;
    }
    vector<ll> res(n, 0);

    auto process = [&](auto get_key, auto get_coord, auto make_diag_limit) {

        vector<tuple<ll,int,int>> V; 
        V.reserve(n);
        for (auto &q : qs) 
            V.emplace_back(get_key(q), get_coord(q), q.idx);

        sort(V.begin(), V.end(), [](auto &a, auto &b){
            if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
            return get<1>(a) < get<1>(b);
        });

        int i = 0, sz = V.size();
        while (i < sz) {
            int j = i+1;

            while (j < sz && get<0>(V[j]) == get<0>(V[i])) ++j;

            ll bound_low, bound_high;
            tie(bound_low, bound_high) = make_diag_limit(get<0>(V[i]));
            for (int t = i; t < j; ++t) {
                int coord = get<1>(V[t]);
                int idx   = get<2>(V[t]);
                ll prev = (t > i ? get<1>(V[t-1]) : bound_low);
                ll next = (t < j-1 ? get<1>(V[t+1]) : bound_high);
                res[idx] += (coord - prev - 1) + (next - coord - 1);
            }
            i = j;
        }
    };

    process(
        [](auto &q){ return (ll)q.r; },
        [](auto &q){ return q.c; },
        [&](ll ){ return pair<ll,ll>{0, k+1}; }
    );

    process(
        [](auto &q){ return (ll)q.c; },
        [](auto &q){ return q.r; },
        [&](ll ){ return pair<ll,ll>{0, k+1}; }
    );

    process(
        [](auto &q){ return (ll)q.r - q.c; },
        [](auto &q){ return q.r; },
        [&](ll d){

            ll low  = max(1LL, 1LL + d);
            ll high = min(k, k + d);
            return pair<ll,ll>{low - 1, high + 1};
        }
    );

    process(
        [](auto &q){ return (ll)q.r + q.c; },
        [](auto &q){ return q.r; },
        [&](ll a){

            ll low  = max(1LL, a - k);
            ll high = min(k, a - 1);
            return pair<ll,ll>{low - 1, high + 1};
        }
    );

    for (ll x : res) 
        cout << x << '\n';

    return 0;
}