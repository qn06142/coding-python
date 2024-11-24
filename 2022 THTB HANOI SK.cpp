#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, a[100005], R[100005], L[100005];
	long long pre[100005], suf[100005];
	map<long long, int> mp;
	map<pair<long long, long long>, int> pos;
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	mp[0] = 1;
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + a[i];
		L[i] = mp[pre[i]];
		mp[pre[i]]++;
	}
	mp.clear();
	mp[0] = 1;
	for (int i  = n; i >= 1; i--) {
		suf[i] = suf[i+1] + a[i];
		R[i] = mp[suf[i]];
		mp[suf[i]]++;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int j = pos[{pre[i], suf[i]}];
		ans += 1LL * (L[i] -L [j]) * R[i];
		pos[{pre[i], suf[i]}] = i;
	}
	cout << ans;
}
