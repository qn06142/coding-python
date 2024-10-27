#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, f[N], nxt[N];
string a, b;
int getNum(int l, int r) {
	int ans = 0;
	for (int i = l; i <= r; ++i) {
		ans *= 10;
		ans += b[i] - '0';
	}
	return ans;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
	    // freopen("TEST.inp", "r", stdin);
	    // freopen("TEST.out", "w", stdout);
    #else
    	// freopen("TEST.inp", "r", stdin);
    	// freopen("TEST.out", "w", stdout);
    #endif
    cin >> a;
    cin >> b;
    if (a == b) {
    	cout << 1 << ' ' << 1 << '\n';
    	return 0;
    }
    n = a.size();
    m = b.size();
    a = "#" + a + "#";
    b = "#" + b + "#";
    int maxPrefix = 0, maxSuffix = 0;
    while (maxPrefix < min(n, m) && a[1 + maxPrefix] == b[1 + maxPrefix]) ++maxPrefix;
    while (maxSuffix < min(n, m) && a[n - maxSuffix] == b[m - maxSuffix]) ++maxSuffix;
    for (int i = 1; i <= n; ++i) {
    	f[i] = f[i - 1] + a[i] - '0';
    }
    nxt[m + 1] = m + 1;
    for (int i = m; i >= 1; --i) {
    	nxt[i] = nxt[i + 1];
    	if (b[i] != '0') nxt[i] = i;
    }
    for (int l = 1; l <= min(n, m); ++l) {
    	if (b[l] == '0') continue;
    	for (int r = l; r <= min({m, l + 10}); ++r) {
    		int l1 = l, r1 = n - (m - r);
    		if (l1 > r1) continue;
    		if (l - 1 > maxPrefix || m - r > maxSuffix) continue;
    		if (getNum(l, r) == f[r1] - f[l1 - 1]) {
    			cout << l1 << ' ' << r1 << '\n';
    			assert(1 <= l1 && l1 <= r1 && r1 <= n);
    			string a1 = (l1 - 1? a.substr(1, l1 - 1) : "") + to_string(f[r1] - f[l1 - 1]) 
    			+ (n - r1? a.substr(r1 + 1, n - r1) : "");
    			assert(a1 == b.substr(1, m));
    			return 0;
    		}
    	}
    	// for (int r = l; r <= min({m, l + 10}); ++r) {
    	// 	int l1 = l, r1 = n - (m - r);
    	// 	if (l1 > r1) continue;
    	// 	if (l - 1 > maxPrefix || m - r > maxSuffix) continue;
    	// 	if (getNum(l, r) == f[r1] - f[l1 - 1]) {
    	// 		cout << l1 << ' ' << r1 << '\n';
    	// 		// string a1 = (1 <= l1 - 1? a.substr(1, l1 - 1) : "") + to_string(f[r1] - f[l1 - 1]) 
    	// 		// + (r1 + 1 <= n? a.substr(r1 + 1, m - r) : "");
    	// 		// assert(a1 == b);
    	// 		return 0;
    	// 	}
    	// }
    }
    return 0;
}
/*
*/
