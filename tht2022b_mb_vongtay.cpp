#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n, m, s;
int c[MAXN];

void solve(int idx, int cnt, int sum, int &res) {
    if(cnt == m) {
        if(sum == s) res++;
        return;
    }
    if(idx > n || sum > s) return;
    solve(idx + 1, cnt + 1, sum + c[idx], res); // include current bead
    solve(idx + 1, cnt, sum, res); // exclude current bead
}

int main() {
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) cin >> c[i];

    int res = 0;
    solve(1, 0, 0, res);
    cout << res << endl;

    return 0;
}
