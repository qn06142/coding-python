#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll LINF = 1e18;

int N, A, B;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> A >> B;  

	vector<long long> pfx(N + 1);
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		pfx[i] = a + pfx[i - 1];  
	}

	ll ret = -LINF;
	multiset<ll> ms;

	for (int i = A; i <= N; ++i) {
		if (i > B) ms.erase(ms.find(pfx[i - B - 1]));  
		ms.insert(pfx[i - A]);
		ret = max(ret,
		          pfx[i] - *ms.begin());  
	}

	cout << ret << "\n";
}