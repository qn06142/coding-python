#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const __int128 NEG_INF = (__int128) -9e36;

string i128_to_string(__int128 x) {
    if (x == 0) return "0";
    bool neg = (x < 0);
    if (neg) x = -x;
    string s;
    while (x > 0) {
        int d = (int)(x % 10);
        s.push_back('0' + d);
        x /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

int n, MAXB, B, maxPos, P;
long long k;
long long L, R;
vector<long long> a;
vector<int64> c1;
int64 nn;
__int128 C;
vector<__int128> s;
vector<char> seen;
vector<__int128> dpv;
vector<unsigned long long> dpc;

inline int getbit(long long val, int pos) {
    return ((val >> pos) & 1LL) ? 1 : 0;
}

size_t idx4(int pos, int tL, int tR, int rem) {
    return (((size_t)pos * 2 + tL) * 2 + tR) * (size_t)k + (size_t)rem;
}

pair<__int128, unsigned long long> recur(int pos, int tightl, int tightr, int rem) {
    if (pos < 0) {
        if (rem % k == 0) return {0, 1ULL};
        else return {NEG_INF, 0ULL};
    }
    size_t id = idx4(pos, tightl, tightr, rem);
    if (seen[id]) {
        return {dpv[id], dpc[id]};
    }
    seen[id] = 1;
    __int128 best = NEG_INF;
    unsigned long long ways = 0ULL;

    int lb = tightl ? getbit(L, pos) : 0;
    int ub = tightr ? getbit(R, pos) : 1;
    for (int b = lb; b <= ub; ++b) {
        int ntl = tightl && (b == lb);
        int ntr = tightr && (b == ub);
        int newrem = (int)(((long long)rem * 2 + b) % k);
        auto sub = recur(pos - 1, ntl, ntr, newrem);
        __int128 subval = sub.first;
        if (subval == NEG_INF) continue;
        __int128 cur = subval + ((__int128)b) * s[pos];
        if (cur > best) {
            best = cur;
            ways = sub.second;
        } else if (cur == best) {
            ways += sub.second;
        }
    }
    dpv[id] = best;
    dpc[id] = ways;
    return {best, ways};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> L >> R >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if(k > sqrt(1e9)) {
        long long bs = LLONG_MIN;
        long long bx = -1;
        int bc = 0;
        for(int x = ((L + k - 1) / k) * k; x <= R; x += k) {
            long long s = 0;
            for (int i = 0; i < n; ++i) {
                s += (a[i] ^ x);
            }
            
            if (s > bs) {
                bs = s;
                bx = x;
                bc = 1;
            } 
            else if (s == bs) {
                bc++;
            }
        }
        cout << bs << '\n';
        cout << bc;
        return 0;
    }
    MAXB = 0;
    long long mx = R;
    for (auto v: a) if (v > mx) mx = v;
    while ((1LL << MAXB) <= mx) ++MAXB;
    MAXB = max(MAXB, 60);

    c1.assign(MAXB + 1, 0);
    for (auto v : a) {
        for (int j = 0; j <= MAXB; ++j) {
            if ((v >> j) & 1LL) c1[j]++;
        }
    }
    nn = n;
    C = 0;
    s.resize(MAXB + 1);
    for (int j = 0; j <= MAXB; ++j) {
        __int128 bitval = (__int128)1 << j;
        C += (__int128)c1[j] * bitval;
        __int128 cj = (__int128)(nn - 2 * c1[j]);
        s[j] = cj * bitval;
    }

    B = MAXB;
    maxPos = B;
    P = maxPos + 1;

    if (k == 0) k = 1;
    size_t states = (size_t)P * 2 * 2 * (size_t)k;
    seen.assign(states, 0);
    dpv.assign(states, NEG_INF);
    dpc.assign(states, 0ULL);

    auto ans = recur(maxPos, 1, 1, 0);
    __int128 ans_ = ans.first;
    unsigned long long count = ans.second;

    if (ans_ == NEG_INF) {
        cout << i128_to_string(C) << "\n" << 0 << "\n";
        return 0;
    }
    __int128 total = C + ans_;
    cout << i128_to_string(total) << "\n" << count << "\n";
}
