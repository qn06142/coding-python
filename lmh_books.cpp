#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 5;
long long a[maxn];
long long b[maxn]; 
int cnt[maxn];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	int l = 1, r = n + 1;
	long long suml = 0, sumr = 0;
	int ans = 0;
    while (r - 1 >= 1 && cnt[a[r - 1]] == 0 && sumr + b[r - 1] <= m) {
        --r;
        cnt[a[r]]++;
        sumr += b[r];
    }
    ans = max(ans, 0 + (n - r + 1));
	while(l <= n and r <= n + 1) {
		while((cnt[a[l]] > 0 or suml + sumr + b[l] > m) and (r <= n) ) {
			sumr -= b[r];
			cnt[a[r]]--;
			r++;
		}

		if (cnt[a[l]] == 0 && suml + sumr + b[l] <= m) { 
            suml += b[l]; 
            cnt[a[l]]++; 
            ans = max(ans, l + (n - r + 1)); 
        } 
        else { 
            break;
        }
        l++;
	}
	cout << ans;
}
