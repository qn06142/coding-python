#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const long long INF = 1e18;
const int N = 3e5 + 10;
int n, a[N], b[N];
int sta[N], head;
long long f[N], mx[N];
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 0; i <= n; i++) f[i] = mx[i] = -INF;
    for(int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + b[i];
        while(head && a[sta[head]] >= a[i])
        {
            mx[sta[head - 1]] = max(mx[sta[head - 1]], mx[sta[head]]);
            head-- ;
        }
        f[i] = max(f[i], f[sta[head]]);

        f[i] = max(f[i], mx[sta[head]] + b[i]);

        if(head == 0) f[i] = max(f[i], 1ll * b[i]);

        sta[++head] = i;
        mx[i] = max(mx[i], f[i]);

    }
    cout << f[n] << '\n';
}