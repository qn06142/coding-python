#include<bits/stdc++.h>
#define X first
#define Y second
#define all(x) begin(x), end(x)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

template<class A, class B>
    bool maximize(A& x, B y) {
        if (x < y) return x = y, true; else return false;
    }

const int N = 10007;

int n, k;

ll dp[10007][2007];

pii a[10007];

vector<pair<int, int>> vec[N];
vector<pair<int, int>> opt[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>k>>n;
    FOR(i, 1, n) {
        int c, e, l;
        cin>>c>>e>>l;
        vec[c].push_back({e, l});
    }
    n = 0;
    FOR(i, 1, k) {
        sort(all(vec[i]), greater<pii>()); 
        for (auto x : vec[i]) {
            int soluong = x.Y;
            FOR(t, 1, soluong) {
                if ((int)opt[i].size() * i > k) break;
                opt[i].push_back({x.X, i}); 

            }
        }
        for (auto x : opt[i]) a[++n] = x;
    }

    dp[0][0] = 0;
    REP(i, 0, n)
        for (int j = 0; j <= k; j++) {

            maximize(dp[i + 1][j], dp[i][j]);

            if (j + a[i + 1].Y <= k) maximize(dp[i + 1][j + a[i + 1].Y], dp[i][j] + a[i + 1].X);
        }
    ll res = 0;
    FOR(j, 0, k) maximize(res, dp[n][j]);
    cout<<res;
    return 0;
}