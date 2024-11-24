#pragma GCC optmization("trapv")
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll MOD1 = 1000000000000037;
ll prime1 = 313;
vector<ll> p1;

ll get_hash(string &s) {
    int l = s.length();
    ll hash1 = 0;
    for(int i = 0; i < l; i++) {
        int idx = s[i];
        hash1 = (hash1 + (idx * p1[i]) % MOD1) % MOD1;
    }
    return hash1;
}

void solve() {
    p1 = vector<ll>(1e6, 1);
    for(int i = 1; i <= 7e5; i++) {
        p1[i] = (p1[i - 1] * prime1) % MOD1;
    }

    int n, m;
    cin >> n >> m;
    map<ll, int> mpp1;

    while(n--) {
        string s;
        cin >> s;
        int l = s.length();
        ll hash1 = get_hash(s);
        mpp1[hash1] = l;
    }

    while(m--) {
        string s;
        cin >> s;

        int l = s.length();
        ll hash1 = get_hash(s);

        bool f = false;
        for(int i = 0; i < l; i++) {
            int idx = s[i];
            for(int j = 'a'; j <= 'c'; j++) {
                if(j != idx) {
                    ll _hash1 = (hash1 - idx * p1[i] + j * p1[i] + 4 * MOD1) % MOD1;
                    if(mpp1.find(_hash1) != mpp1.end()) {
                        f |= true;
                    }
                }
            }
        }

        if(f) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
