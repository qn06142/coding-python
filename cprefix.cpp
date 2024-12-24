#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

const long long MOD = 1e9 + 7;
const long long MOD1 = 1e9 + 9;
const int BASE = 373;
const int BASE1 = 313;

const int MAXN = 1e6 + 5;

long long hashs[MAXN];
long long hashs1[MAXN];
long long reverse_hashs[MAXN];
long long reverse_hashs1[MAXN];
long long powmod[MAXN];
long long powmod1[MAXN];

string s;
int n;

void calcpow() {
    powmod[0] = powmod1[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        powmod[i] = (powmod[i - 1] * BASE) % MOD;
        powmod1[i] = (powmod1[i - 1] * BASE1) % MOD1;
    }
}

void calchash() {
    for (int i = 1; i <= n; i++) {
        hashs[i] = (hashs[i - 1] * BASE + (int)s[i]) % MOD;
        hashs1[i] = (hashs1[i - 1] * BASE1 + (int)s[i]) % MOD1;
    }
    for (int i = n; i >= 1; i--) {
        reverse_hashs[i] = (reverse_hashs[i + 1] * BASE + (int)s[i]) % MOD;
        reverse_hashs1[i] = (reverse_hashs1[i + 1] * BASE1 + (int)s[i]) % MOD1;
    }
}

pair<int, int> calchash(int l, int r) {
    long long hash_value = ((hashs[r] - hashs[l - 1] * powmod[r - l + 1]) % MOD + MOD) % MOD;
    long long hash_value1 = ((hashs1[r] - hashs1[l - 1] * powmod1[r - l + 1]) % MOD1 + MOD1) % MOD1;
    return {hash_value, hash_value1};
}

pair<int, int> calcreversehash(int l, int r) {
    long long hash_value = ((reverse_hashs[l] - reverse_hashs[r + 1] * powmod[r - l + 1]) % MOD + MOD) % MOD;
    long long hash_value1 = ((reverse_hashs1[l] - reverse_hashs1[r + 1] * powmod1[r - l + 1]) % MOD1 + MOD1) % MOD1;
    return {hash_value, hash_value1};
}
void print(int l, int r) {
    cerr << s.substr(l, r - l + 1) << '\n';
}
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    vector<int> pi = prefix_function(s);
    n = s.size();
    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++)
        ans[pi[i]]++;
    for (int i = n-1; i > 0; i--)
        ans[pi[i-1]] += ans[i];
    for (int i = 0; i <= n; i++)
        ans[i]++;
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}
