#include<bits/stdc++.h>

using namespace std;
long long hashs[(int) 1e6 + 5];
long long powmod[(int) 1e6 + 5];
const long long mod = 1e9 + 7;
const long long modsquared = (mod * mod);
const int base = 373;
#define int long long
void calcpow() {
    powmod[0] = 1;
    for(int i = 1; i <= 1e6; i++) {
        powmod[i] = (base * powmod[i - 1]) % mod;
    }
}

string s;
string subs;

int n;
void calchash() {
    for(int i = 1; i <= n; i++) {
        hashs[i] = (hashs[i - 1] * base + (int) s[i]) % mod;
    }
}
int calchashsubs() {
    int hashs = 0;
    for(int i = 1; i < subs.size(); i++) {
        hashs = (hashs * base + (int) subs[i]) % mod;
    }
    return hashs;
}
int calchash(int l, int r) {
    return ((long long) hashs[r] - (long long) hashs[l - 1] * powmod[r - l + 1] + modsquared) % mod;
}
signed main() {
    cin >> s;
    s = ' ' + s;
    cin >> subs;
    subs = ' ' + subs;
    n = s.size();
    calcpow();
    calchash();
    int subshash = calchashsubs();
    //cout << subshash << endl;
    for(int i = 1; i <= n; i++) {
        //cout << calchash(i, i + subs.size() - 2) << endl;
        if(i + subs.size() - 2 > n) break;
        if(calchash(i, i + subs.size() - 2) == subshash) {
            cout << i << ' ';
        }
    }
}