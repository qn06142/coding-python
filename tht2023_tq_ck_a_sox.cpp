#include <bits/stdc++.h>
using namespace std;
int ceil(int a, int b) {
	return (a + b - 1) / b;
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
 	int n, x;
 	cin >> n >> x;
 	int step = min(ceil(x, 4), ceil(n - x + 1, 2)) - 1;   
 	int l = 1 + step * 4;
 	int r = n - step * 2;
 	int cur = step * 6 + 1;
 	while (1) {
 		if (cur % 3 == 1) {
 			if (cur % 2 == 1) ++l;
 			else --r;
 			if (l > x || r < x) cout << "A\n";
 		}
 		if (cur % 3 == 2) {
 			++l;
 			if (l > x || r < x) cout << "B\n";
 		}
 		if (cur % 3 == 0) {
 			if (cur % 2 == 0) ++l;
 			else --r;
 			if (l > x || r < x) cout << "C\n";
 		}
		if (l > x || r < x) break;
		++cur;
 	}
    return 0;
}