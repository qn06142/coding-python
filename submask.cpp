#include <iostream>
#include <immintrin.h>

using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("bmi,arch=skylake,tune=native")
const int MAXN = 200005;

int a[MAXN];
int ans[MAXN];
int cnt[(1 << 16)];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        for (int s=a[i]; s; s=(s-1)&a[i]) ans[i] += cnt[s];
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
