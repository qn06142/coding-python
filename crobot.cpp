#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll INF = 1000000000000000007LL; 

vector<vector<ll>> multiply(const vector<vector<ll>> &A, const vector<vector<ll>> &B, int n) {
    vector<vector<ll>> C(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (A[i][k] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (B[k][j] == INF) continue;
                C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
            }
        }
    }
    return C;
}

vector<vector<ll>> pow(vector<vector<ll>> base, ll exp, int n) {

    vector<vector<ll>> res(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++) {
        res[i][i] = 0;
    }

    while(exp > 0) {
        if(exp & 1) {
            res = multiply(res, base, n);
        }
        base = multiply(base, base, n);
        exp >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<vector<ll>> A(n, vector<ll>(n, INF));

    for (int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;

        A[u-1][v-1] = min(A[u-1][v-1], w);
    }

    vector<vector<ll>> P = pow(A, k, n);

    ll ans = INF;
    for (int i = 0; i < n; i++){
        ans = min(ans, P[i][i]);
    }

    if(ans >= INF) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}