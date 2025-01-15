#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn = 2e5 + 5;
ll n, a[mn], dp[mn], pd[mn], m, ans;

void solve(){
	cin >> m >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 0; i <= m; ++i) dp[i] = pd[i] = -30;
	dp[m] = 0;
	ans = -1e18;
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			for(int h = m; h >= a[j] * i; --h){
				pd[h - a[j] * i] = max(pd[h - a[j] * i], dp[h] + a[j]);
			} 
		}
		for(int j = 0; j <= m; ++j) dp[j] = pd[j], pd[j] = -1e18;
		ans = max(ans, dp[0]);
//		cout << "\n";
	}
	cout << (ans > 0 ? ans : -1);
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen(".INP", "r", stdin);
	//freopen(".OUT", "w", stdout);
	int testCase = 1;
	//cin >> testCase;
	while(testCase--) solve();
}

