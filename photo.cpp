#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b;
struct custom {
	int h, l, i;
	bool operator<(custom other) {
		return other.l * a + other.h * b > l * a + h * b;
	}
	custom() {}
};
custom ar[(int) 1e5 + 5];
signed main() {
	int n, d;
	cin >> n >> d;
    cin >> a >> b;
	for(int i = 1; i <= n; i++) {
		cin >> ar[i].l >> ar[i].h;
        ar[i].i = i;
	}
	sort(ar + 1, ar + 1 + n);
	int i = 1;
	deque<int> ans;
    for(int i = 1; i <= n; i++) {
        int req = ar[i].l * a + ar[i].h * b;
        if(req <= d) {
            ans.push_back(ar[i].i);
            d -= req;
        } else {
            break;
        }
    }
	cout << ans.size() << '\n';
	for(int i : ans) {
		cout << i << ' ';
	}
}
