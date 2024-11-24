#include<bits/stdc++.h>
#define task "E"
#define ll long long
using namespace std;
const int maxn = 2 * (1e5 + 7);
const int logn = 19;
const ll inf = 1e18 + 1;
const int mod = 998244353;

int dp[maxn][logn],n,m,snt[maxn];

void Input()
{
    cin >> n >> m;
}

void sum (int& a,int b)
{
    a += b;
    a %= mod;
    if (a < 0) a += mod;
}

void SangNT()
{
    for (int i = 2; i * i < maxn; i++)
    {
        if (snt[i] == 0)
        {
            for (int j = i * i; j < maxn; j += i)
            {
                snt[j] = i;
            }
        }
    }
}

void Solve()
{
    SangNT();
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < logn; j++)
        {
            dp[i][j] = 0;
            for (int k = 0; k <= j; k++)
                sum(dp[i][j],dp[i - 1][k]);
        }
    }
    int ans = 0;
    for (int l = 1; l <= m; l++)
    {
        vector<pair<int,int>> pd;
        int cur = l;
        while (cur > 1)
        {
            int p = snt[cur], cnt = 0;
            while (snt[cur] == p)
            {
                cur /= p;
                ++cnt;
            }
            pd.push_back(make_pair(p,cnt));
        }

        int d = 1;
        for (auto& t : pd)
        {
            d = ((ll)d * dp[n][t.second] % mod) % mod;
        }
        sum(ans,d);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(task".INP","r",stdin);
    //freopen(task".OUT","w",stdout);
    Input();
    Solve();
}
