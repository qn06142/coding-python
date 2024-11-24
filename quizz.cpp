#include <bits/stdc++.h>
#define task "QUIZZ"
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
using namespace std;
const int MAXN = 2e5 + 5;
const ll INF = 1e18 + 5;
const ll MOD = 1e9 + 7;

int n, a[MAXN];

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

vector<pair<int, int>> Adj[MAXN];
ll cnt[MAXN];

ll power(ll a, ll b)
{
    ll res = 1;
    for (; b; b /= 2)
    {
        if (b & 1)
        {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
    }
    return res;
}

int sang[MAXN];
ll L[MAXN], R[MAXN];

void Solve()
{
    for (int i = 2; i * i <= 2e5; i++)
    {
        if (!sang[i])
            for (int j = i * i; j <= 2e5; j += i)
            {
                if (!sang[j])
                    sang[j] = i;
            }
    }

    vector<int> snt;
    for (int i = 2; i <= 2e5; i++)
        if (!sang[i])
        {
            snt.pb(i);
            sang[i] = i;
        }

    for (int i = 1; i <= n; i++)
    {
        int num = a[i];
        while (num > 1)
        {
            int p = sang[num];
            int sl = 0;
            while (sang[num] == p)
            {
                num /= p;
                sl++;
            }
            Adj[p].pb({sl, i});
        }
    }

    ll ans = 1;
    for (int x : snt)
    {
        stack<pair<int, int>> S;
        for (int i = 0; i < Adj[x].size(); i++)
        {
            while (!S.empty() && S.top().fi < Adj[x][i].fi)
            {
                S.pop();
            }

            if (S.empty())
                L[i] = 0;
            else
                L[i] = S.top().se;
            S.push(Adj[x][i]);
        }

        while (!S.empty())
            S.pop();
        //assert(1 < 0);
        for (int i = (int)Adj[x].size() - 1; i >= 0; i--)
        {
            while (!S.empty() && S.top().fi <= Adj[x][i].fi)
            {
                S.pop();
            }
            if (S.empty())
                R[i] = n + 1;
            else
                R[i] = S.top().se;
            S.push(Adj[x][i]);
        }

        for (int i = 0; i < Adj[x].size(); i++)
        {
            ans *= power(power(x, Adj[x][i].fi), (Adj[x][i].se - L[i]) * (R[i] - Adj[x][i].se));
            ans %= MOD;
        }
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();
}
