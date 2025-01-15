#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("trapv")
const long long MOD = 1e9 + 7;
const long long MOD1 = 1e9 + 9;
const long long MOD_SQUARED = (MOD * MOD);
const long long MOD1_SQUARED = (MOD1 * MOD1);
const int BASE = 373;
const int BASE1 = 313;

long long hashs[(int) 1e6 + 5];
long long hashs1[(int) 1e6 + 5];
long long powmod[(int) 1e6 + 5];
long long powmod1[(int) 1e6 + 5];

string s, subs;
int n;

void calcpow() {
    powmod[0] = powmod1[0] = 1;
    for (int i = 1; i <= 1e6; i++) {
        powmod[i] = (powmod[i - 1] * BASE) % MOD;
        powmod1[i] = (powmod1[i - 1] * BASE1) % MOD1;
    }
}

void calchash() {
    for (int i = 1; i <= n; i++) {
        hashs[i] = (hashs[i - 1] * BASE + (int)s[i]) % MOD;
        hashs1[i] = (hashs1[i - 1] * BASE1 + (int)s[i]) % MOD1;
    }
}

pair<int, int> calchashsubs() {
    long long hash_value = 0, hash_value1 = 0;
    for (int i = 1; i < subs.size(); i++) {
        hash_value = (hash_value * BASE + (int)subs[i]) % MOD;
        hash_value1 = (hash_value1 * BASE1 + (int)subs[i]) % MOD1;
    }
    return {hash_value, hash_value1};
}

pair<int, int> calchash(int l, int r) {
    long long hash_value = ((hashs[r] - hashs[l - 1] * powmod[r - l + 1]) % MOD + MOD) % MOD;
    long long hash_value1 = ((hashs1[r] - hashs1[l - 1] * powmod1[r - l + 1]) % MOD1 + MOD1) % MOD1;
    return {hash_value, hash_value1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> subs;
    subs = ' ' + subs; 
    cin >> s;
    s = ' ' + s; 
    n = s.size() - 1;

    calcpow();
    calchash();
    vector<int> cnt;
    pair<int, int> subshash = calchashsubs();
    bool ans = false;
    for (int i = 1; i <= n; i++) {
        if (i + subs.size() - 2 > n) break;
        if (calchash(i, i + subs.size() - 2) == subshash) {
            cnt.push_back(i - 1);
            ans = true;
        }
    }

    cout << cnt.size() << '\n';
    for(int i : cnt) cout << i << ' ';
    return 0;
}