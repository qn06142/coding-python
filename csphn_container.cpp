#include<bits/stdc++.h>
using namespace std;
array<int, 200005> a;
set<pair<int, int>> containers;
int main() {
	int m, w, n;
	cin >> m >> w >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) {
		containers.insert(make_pair(i + 1, w));
	}
	for(int i = 0; i < n; i++) {
		auto tmp = containers.lower_bound(make_pair(0, a[i]));
		if(tmp == containers.end()) {
			cout << -1 << "\n";
		} else {
			cout << tmp->first << "\n";
			int tmpsecond = tmp->second, tmpfirst = tmp->first;
			containers.erase(tmp);
			containers.insert(make_pair(tmpfirst, tmpsecond - a[i]));
		}
	}
}