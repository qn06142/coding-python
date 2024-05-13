#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long m, n;
    cin >> m >> n;

    vector<vector<long long>> mat(m, vector<long long>(n));
    vector<long long> rowpre(m, 0), colpre(n, 0);

    for(long long i = 0; i < m; i++) {
        for(long long j = 0; j < n; j++) {
            cin >> mat[i][j];
            rowpre[i] += mat[i][j];
            colpre[j] += mat[i][j];
        }
    }

    long long q;
    cin >> q;

    while(q--) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        cout << rowpre[u] + colpre[v] - mat[u][v] << "\n";
    }

    return 0;
}
