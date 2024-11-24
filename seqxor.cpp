#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int mod = 1e9 + 7;

long long binpow(long long a, long long b, long long m = mod) {
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

int main() {
    int n;
    cin >> n;
    map<int, pair<long long, int>> cnt;
    vector<int> a(n + 1), prefx(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        prefx[i] = prefx[i - 1] ^ a[i];
    }

    long long ans = 0;
    cnt[0] = {1, 1};
    for(int i = 1; i <= n; i++) {

        ans = (ans + cnt[prefx[i]].first * binpow(2, i - 1) % mod) % mod - cnt[prefx[i]].second;

        cnt[prefx[i]] ={(cnt[prefx[i]].first + binpow(binpow(2, i), mod - 2)) % mod, cnt[prefx[i]].second + 1};
    }

    cout << ans << endl;
    return 0;
}