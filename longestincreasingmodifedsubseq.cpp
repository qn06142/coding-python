#include<bits/stdc++.h>
using namespace std;
int a[(int) 2e5 + 5], l[(int) 2e5 + 5], r[(int) 2e5 + 5];
vector<int> tmp;
int lower_bound_reversed(int x) {
	int l = 0;
	int r = tmp.size() -  1;
	int ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(tmp[mid] > x) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	

	tmp.push_back((int) INT_MIN);
	for(int i = 1; i <= n; i++) {
		if(tmp.back() < a[i]) {
			tmp.push_back(a[i]);
		} else {
			tmp[lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin()] = a[i];
		}
		l[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
		//cout << l[i] << ' ';
	}
	tmp.clear();
	tmp.push_back(INT_MAX);
	//cout << endl;
	for(int i = n; i > 0; i--) {
		if(tmp.back() <= a[i]) {
			r[i] = lower_bound_reversed(a[i] - x) + 1;
			tmp[lower_bound_reversed(a[i]) + 1] = a[i];
		} else {
			tmp.push_back(a[i]);
			r[i] = tmp.size() - 1;
		}
		
		
	}
	
	int ans = INT_MIN;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, r[i] + l[i] - 1);
	}
	//cout << endl;
	cout << ans;
}