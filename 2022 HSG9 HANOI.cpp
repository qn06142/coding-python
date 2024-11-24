#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const int n = 5e2 + 2;
const int m = 5e4 + 2;
int dp[501][50001];
int val[n][m], ans[n];
int n1, m1;
int x[n], y[n], z[n];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n1 >> m1;
	for (int i = 1; i <= n1; i++) cin >> x[i] >> y[i] >> z[i];
	
	for (int i = 1; i <= n1; i++) {
		for (int j = 0; j <= m1; j++) {
			for (int u = 0; u <= min(z[i], j / x[i]); u++) {
				if (dp[i][j] < dp[i-1][j - (u / x[i])] + u * y[i]) {
					dp[i][j] = dp[i-1][j - (u / x[i])] + u * y[i];
					val[i][j] = u;
				}
			}
		}
	}
	cout << dp[n1][m1] << "\n";
	int j = m1;
	for (int i = n1; i >= 1; i--) {
		ans[i] = val[i][j];
		j -= val[i][j] * x[i];
	}
	for (int i = 1; i <= n1; i++) cout << ans[i] << "\n";
}
