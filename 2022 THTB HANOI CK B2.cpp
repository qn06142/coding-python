#include    <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;
const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

ll N, K;
map<ii, ll> bonus;

bool sf(ll x, ll y)
{
    return (x > 0 && y > 0 && x <= N && y <= N);
}

ll awards(ll x, ll y)
{
    ll ret = 0;
    for(int i=0; i<8; i++)
    {
        int ux = x + dx[i], vx = y + dy[i];
        if (sf(ux, vx))
        {
            ret += bonus[mp(ux, vx)];
        }
    }
    return ret;
}

void solve()
{
    cin >> N >> K;
    vector<ii> pos;
    for(int i=0; i<K; i++)
    {
        ll x, y, c;
        cin >> x >> y >> c;
        pos.pb(mp(x, y));
        bonus[pos[i]] = c;
    }

    ll ans = 0;
    for(int i=0; i<K; i++)
    {
        for(int t=0; t<8; t++)
        {
            int ux = pos[i].fi + dx[t];
            int vx = pos[i].se + dy[t];
            if (sf(ux, vx) && !bonus[mp(ux, vx)])
            {
                ans = max(ans, awards(ux, vx));
            }
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

