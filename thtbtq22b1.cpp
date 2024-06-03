#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int n, a[N], mx[N], cnt[N], prime[N], Min[N], mark[N];
vector<int> v;
ll ans = 1;

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!mark[i]) {
            prime[++prime[0]] = i;
            Min[i] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= n; j++) {
            mark[i * prime[j]] = 1;
            Min[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, i;
    cin >> n >> i;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sieve(sqrt(1e7));
    for (int i = 1; i <= prime[0]; i++) v.push_back(prime[i]);
    for (auto x : v) {
        for (int i = 1; i <= n; i++) {
            cnt[i] = 0;
            while (a[i] % x == 0) {
                a[i] /= x;
                cnt[i]++;
            }
            mx[x] = max(mx[x], cnt[i]);
        }
    }
    for (auto x : v) {
        ans = ans * 1ll * ((ll)pow(x, mx[x])) % mod;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > 1) ans = ans * 1ll * a[i] % mod;
    }
    cout << ans;
    return 0;
}
