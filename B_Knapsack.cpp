#include<bits/stdc++.h>
#define ll long long
#define ep emplace_back
#define pll pair<ll, ll>
using namespace std;

const int maxn = 1e5 + 6;
const int S = 2002;

ll n, s;
ll v[maxn + 3], w[maxn + 3], k[maxn + 3];
vector<pll>adj[maxn + 3];
bool check[maxn + 3];
vector<ll>L, P;
vector<pll>dp;

bool cmp(pll a, pll b)
{
    return a.first > b.first;
}

int main()
{
    //freopen("PROC.INP", "r", stdin);
    //freopen("PROC.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> k[i];
        adj[w[i]].ep(v[i], k[i]);
    }
    P = L = vector<ll>(s + 2);
    for(int i = 1; i <= n; i++)
    {
        if(!check[w[i]])
        {
            check[w[i]] = true;
            sort(adj[w[i]].begin(), adj[w[i]].end(), cmp);
            ll temp = 0;
            for(int j = 0; j < adj[w[i]].size(); j++)
            {
                if(temp + w[i] > s) break;
                ll fi = adj[w[i]][j].first;
                ll se = adj[w[i]][j].second;
                while(se-- && temp + w[i] <= s)
                {
                    temp += w[i];
                    dp.ep(w[i], fi);
                }
            }

        }
    }
    for(int i = 0; i < dp.size(); i++)
    {
        for(int j = s; j >= dp[i].first; j--)
        {
            L[j] = max(P[j], L[j - dp[i].first] + dp[i].second);
        }
        P = L;
    }
    cout << L[s];

}