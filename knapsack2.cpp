#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18 + 1e9 + 1;
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> weight(n + 1), value(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> weight[i] >> value[i];

    int sum = 0;
    for (int &x : value) sum += x;

    vector<vector<ll> > f(n + 1, vector<ll>(sum + 1, +LINF));
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        f[i][0] = 0;
        for (int j = 1; j <= sum; ++j)
        {
            if (j >= value[i])
                f[i][j] = min(f[i - 1][j], f[i - 1][j - value[i]] + weight[i]);
            else 
                f[i][j] = f[i - 1][j];
        }
    }

    for (int v = sum; v-->0; )
    {
        if (f[n][v] <= k)
        {
            cout << v;
            return 0;
        }
    }            
}
