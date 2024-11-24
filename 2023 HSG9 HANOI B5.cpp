#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 9;
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>> n;
	int a[n];
	for (int i = 1; i<= n; i++) cin >> a[i];
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int d[2005] = {0};
		int maxi = -1, mini = INT_MAX;
		for (int j = i; j <= n; j++) {
			if (d[a[j]]==0) d[a[j]] ++;
			else break;
			maxi = max(maxi, a[j]);
			mini = min(mini, a[j]);
			if (j-i == maxi-mini) ans++; 
		}
	}
	cout << ans;
}
