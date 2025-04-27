#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static ll modmul(ll a, ll b, ll m) {
    return (__int128)a * b % m;
}

static ll modpow(ll a, ll e, ll m) {
    ll r = 1;
    while (e) {
        if (e & 1) r = modmul(r, a, m);
        a = modmul(a, a, m);
        e >>= 1;
    }
    return r;
}

bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll p : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if (n % p == 0) return n == p;
    }
    ll d = n - 1, s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (a % n == 0) continue;
        ll x = modpow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (int r = 1; r < s; r++) {
            x = modmul(x, x, n);
            if (x == n - 1) {
                comp = false;
                break;
            }
        }
        if (comp) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    int max_ai = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        max_ai = max(max_ai, a[i]);
    }

    vector<int> spf(max_ai+1, 0), primes;
    for (int i = 2; i <= max_ai; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            ll x = 1LL * p * i;
            if (x > max_ai || p > spf[i]) break;
            spf[x] = p;
        }
    }

    bool has_prime_factor = false;
    for (int v : a) if (v > 1) { has_prime_factor = true; break; }
    if (!has_prime_factor) {
        cout << 2 << "\n";
        return 0;
    }

    unordered_map<int, ll> exponent_sum;
    exponent_sum.reserve(primes.size());
    for (int v : a) {
        while (v > 1) {
            int p = spf[v], cnt = 0;
            do {
                v /= p;
                cnt++;
            } while (v % p == 0);
            exponent_sum[p] += cnt;
        }
    }

    ll ans = LLONG_MAX;
    for (int p : primes) {
        if (exponent_sum.find(p) == exponent_sum.end()) {
            ans = p;
            break;
        }
    }

    if (ans == LLONG_MAX) {
        ll cand = max_ai + 1;
        if (cand < 2) cand = 2;
        while (true) {
            if (is_prime(cand)) {
                ans = cand;
                break;
            }
            cand++;
        }
    }

    for (auto &pr : exponent_sum) {
        int p = pr.first;
        ll e = pr.second;
        if (p >= ans) continue;   
        ll val = 1;
        for (ll i = 0; i < e+1; i++) {
            if (val > ans / p) { val = ans; break; }
            val *= p;
        }
        ans = min(ans, val);
    }

    cout << ans << "\n";
    return 0;
}