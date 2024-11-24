#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long hashs[(int) 1e6 + 5];
long long powmod[(int) 1e6 + 5];
const long long mod = 1e9 + 7;
const long long modsquared = (mod * mod);
const long long base = 373;
void calcpow() {
    powmod[0] = 1;
    for(long long i = 1; i <= 1e6; i++) {
        powmod[i] = (base * powmod[i - 1]) % mod;
    }
}

string S;

long long n;
void calchash() {
    for(long long i = 1; i <= n; i++) {
        hashs[i] = (hashs[i - 1] * base + (long long) S[i]) % mod;
    }
}
long long calchash(long long l, long long r) {
    return ((long long) hashs[r] - (long long) hashs[l - 1] * powmod[r - l + 1] + modsquared) % mod;
}
const long long MOD = 2017;
bool check(int r, int mid, int l) {
    int l1 = r - mid + 1;
    int l2 = mid - l;
    int L = 0, R = min(l1, l2), ans = -1;
    while(L <= R) {
        int mid_ = (L + R) / 2;
        if(calchash(l,l + mid_) == calchash(mid, mid + mid_)) {
            ans = mid;
            L = mid_ + 1;
        } else {
            R = mid_ - 1;
        }
    }
    if(ans == -1) {
        return S[mid] > S[l];
    }
    return S[mid + ans] > S[l + ans];
}

int f[(int) 5005][(int) 5005];
int pref[(int) 5005][(int) 5005];
signed main() {

    cin >> S;

    n = S.size();
    
    S = ' ' + S;
    calcpow();
    calchash();
    for (int i = 1; i <= n; ++i) {
        f[i][1] = 1;
        for (int j = 2; j <= i; ++j) { 
            if(S[j] != '0') {
                int len = i - j + 1;
                f[i][j] = pref[j - 1][len - 1];
                int k = j - len;
                if(k >= 1 and S[k] != '0' and check(i, j, k)) {
                    f[i][j] += f[j - 1][k];
                }
                f[i][j] %= MOD;
            }
        }
        for(int yes = 1; yes <= n; yes++) pref[i][yes] = (pref[i][yes - 1] + f[i][i - yes + 1]) % MOD;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += f[n][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
