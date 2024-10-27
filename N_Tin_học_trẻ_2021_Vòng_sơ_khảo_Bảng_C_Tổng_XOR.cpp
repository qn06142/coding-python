#include<bits/stdc++.h>
#define task "XORSUM"
#define ll long long
#define ld long double
#define fi cnt
#define se sum
#define pb push_back
using namespace std;
const int MAXN = 1e5 + 5;
const ll INF = 1e18 + 5;

int n;
ll L, R, k;
int a[MAXN];
int sl[MAXN];


struct TVal
{
    int cnt = 0;
    ll sum = -INF;
};

TVal dp[33][2][2][(int)1e4 + 4];

void Input()
{
    cin >> n >> L >> R >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

TVal F(int i, bool okl, bool okr, int r)
{
    if (i < 0)
    {
        if (r == 0)
            return {1, 0};
        else
            return {0, -INF};
    }
    TVal& res = dp[i][okl][okr][r];
    if (res.sum != -INF)
        return res;
    int minc = !okl ? ((L & (1ll << i)) > 0) : 0;
    int maxc = !okr ? ((R & (1ll << i)) > 0) : 1;
    for (int c = minc; c <= maxc; c++)
    {
        TVal tm = F(i - 1, okl | (c > ((L & (1ll << i)) > 0)), okr | (c < ((R & (1ll << i)) > 0)), (r * 2 + c) % k);
        ll tmp = tm.se + (!c ? (sl[i] * (1ll << i)) : ((n - sl[i]) * (1ll << i)));
        if (res.se == tmp)
        {
            res.fi += tm.fi;
        } else
        if (res.se < tmp)
        {
            res.fi = tm.fi;
            res.se = tmp;
        }
    }
    return res;
}

void Solve()
{
    for (int bits = 0; bits <= 30; bits++)
    {
        for (int i = 1; i <= n; i++)
        {
            if ((a[i] & (1 << bits)) > 0)
                sl[bits]++;
        }
    }
    if (k > 1e4)
    {
        ll ans = 0;
        int cnt = 0;
        ll t = L + (k - (L % k)) % k;
        while (t <= R)
        {
            ll sum = 0;
            for (int i = 0; i <= 30; i++)
            {
                sum += (!((t & (1ll << i)) > 0) ? (sl[i] * (1ll << i)) : ((n - sl[i]) * (1ll << i)));
            }
            if (ans == sum)
            {
                cnt++;
            } else
            if (ans < sum)
            {
                ans = sum;
                cnt = 1;
            }
            t += k;
        }
        cout << ans << '\n' << cnt << '\n';
        return;
    }
    TVal ans = F(30, 0, 0, 0);
    cout << ans.se << '\n' << ans.fi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(task".INP","r",stdin);
    //freopen(task".OUT","w",stdout);
    Input();
    Solve();
}