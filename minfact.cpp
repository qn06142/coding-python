#include <bits/stdc++.h>
using namespace std;

vector<int> build_spf(int n) {
    vector<int> spf(n + 1);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; (long long)i * i <= n; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    return spf;
}

vector<pair<int,int>> factorize(int x, const vector<int> &spf) {
    vector<pair<int,int>> res;
    while (x > 1) {
        int p = spf[x];
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            ++cnt;
        }
        res.emplace_back(p, cnt);
    }
    return res;
}

long long singleexp(long long p, long long E) {
    if (E <= 0) return 0;

    long long l = 0, r = p * E;
    if (r < 1) r = 1; 
    while (l < r) {
        long long mid = (l + r) >> 1;

        long long tmp = mid;
        long long cnt = 0;
        while (tmp) {
            tmp /= p;
            cnt += tmp;
            if (cnt >= E) break; 
        }
        if (cnt >= E) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<pair<int,int>> qs;
    qs.reserve(t);
    int max_num = 1;
    for (int i = 0; i < t; ++i) {
        int num, exp;
        cin >> num >> exp;
        qs.emplace_back(num, exp);
        if (num > max_num) max_num = num;
    }

    auto spf = build_spf(max(2, max_num));

    for (auto &q : qs) {
        int num = q.first;
        int exp = q.second;
        if (num == 1) { 
            cout << 0 << '\n';
            continue;
        }
        long long ans = 0;
        auto facs = factorize(num, spf);
        for (auto &pe : facs) {
            long long p = pe.first;
            long long e = pe.second;
            long long E = e * 1LL * exp;
            long long cur = singleexp(p, E);
            if (cur > ans) ans = cur;
        }
        cout << ans << '\n';
    }
}