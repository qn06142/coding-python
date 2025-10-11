#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long double avg_val(ll a, ll b, ll k, int parity) {
    ll cnt1 = k/2, cnt2 = k/2;
    if (k & 1) {
        if (parity == 0) cnt1++;
        else cnt2++;
    }
    return (cnt1*(long double)a + cnt2*(long double)b) / k;
}

ll solve_one(ll a, ll b, ll c) {
    long double ans = 1e300;
    ll best_k = 1;

    long double d1 = fabs(a - (long double)c);
    long double d2 = fabs(b - (long double)c);
    if (d1 < ans) { ans = d1; best_k = 1; }
    if (d2 < ans) { ans = d2; best_k = 1; }

    long double mid = (a + b) / 2.0;
    long double dmid = fabs(mid - c);
    if (dmid < ans || (dmid == ans && 2 < best_k)) {
        ans = dmid;
        best_k = 2;
    }
    if (ans == 0) return best_k;

    vector<ll> cand = {1,2};
    ll den = a + b - 2*c;
    if (den != 0) {

        long double m0 = (long double)(c - a) / den;
        if (m0 >= 0) {
            ll mf = floor(m0);
            for (ll dm = -1; dm <= 1; ++dm) {
                ll m = mf + dm;
                if (m < 0) continue;
                ll k = 2*m + 1;
                cand.push_back(k);
            }
        }

        long double m1 = (long double)(c - b) / den;
        if (m1 >= 0) {
            ll mf = floor(m1);
            for (ll dm = -1; dm <= 1; ++dm) {
                ll m = mf + dm;
                if (m < 0) continue;
                ll k = 2*m + 1;
                cand.push_back(k);
            }
        }
    }
    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    for (ll k : cand) {
        if (k <= 0) continue;
        int parity;
        if (k == 1) parity = (fabs(a-c) <= fabs(b-c) ? 0 : 1);
        else if (k % 2 == 0) parity = 0; 
        else {

            long double v0 = avg_val(a, b, k, 0);
            long double v1 = avg_val(a, b, k, 1);
            parity = (fabs(v0 - c) <= fabs(v1 - c) ? 0 : 1);
        }
        long double av = avg_val(a, b, k, parity);
        long double dist = fabs(av - c);
        if (dist < ans || (fabs(dist - ans) < 1e-12 && k < best_k)) {
            ans = dist;
            best_k = k;
        }
    }
    return best_k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        ll a,b,c; cin >> a >> b >> c;
        cout << solve_one(a,b,c) << '\n';
    }
}