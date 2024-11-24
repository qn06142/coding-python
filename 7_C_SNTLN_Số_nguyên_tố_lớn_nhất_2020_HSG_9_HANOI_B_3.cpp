#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool fermat(int n, int iter = 100) {
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < iter; i++) {
        int a = 2 + rng() % (n - 3);
        if (binpow(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

bool isprime[(int) 1e7 + 5];
vector<int> primes;

bool check(int n) {
    if (n <= 1e7) return isprime[n];
    return fermat(n);
}

signed main() {
    string s;
    cin >> s;
    memset(isprime, 1, sizeof isprime);

    for (int i = 2; i * i <= 1e7; i++) {
        if (isprime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= 1e7; j += i) {
                isprime[j] = false;
            }
        }
    }

    long long ans = 0;
    string tmp = "";
    int n = s.size();
    s = " " + s; 

    for (int i = 1; i <= n; i++) {
        if (!isdigit(s[i]) && !tmp.empty()) {
            for (int k = 0; k < tmp.size(); k++) {
                int tmp1 = 0;
                for (int j = k; j < tmp.size(); j++) {
                    tmp1 = tmp1 * 10 + (tmp[j] - '0');
                    if (tmp1 > 1e5) break; 
                    if (check(tmp1)) {
                        ans = max(ans, (long long) tmp1);
                    }
                }
            }
            tmp.clear();
        } else if (isdigit(s[i])) {
            tmp += s[i];
        }
    }

    if (!tmp.empty()) {
        for (int k = 0; k < tmp.size(); k++) {
            int tmp1 = 0;
            for (int j = k; j < tmp.size(); j++) {
                tmp1 = tmp1 * 10 + (tmp[j] - '0');
                if (tmp1 > 1e5) break; 
                if (check(tmp1)) {
                    ans = max(ans, (long long) tmp1);
                }
            }
        }
    }

    cout << ans;
}