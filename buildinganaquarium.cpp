#include<bits/stdc++.h>

using namespace std;
long long a[(int) 2e5 + 5];

void solve() {
	int n;
	long long x;
	cin >> n >> x;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
    long long l = 0, r =  1e10;
    while(l < r) {
        long long mid = l + (r - l + 1) / 2;
        long long sum_ = 0;
        for(int i = 0; i < n; i++) {
            sum_ += max(mid - a[i], 0LL);
        }
        if(sum_ <= x) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {;
        solve();
    }
}