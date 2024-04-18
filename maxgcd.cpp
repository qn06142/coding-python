#include <bits/stdc++.h>
using namespace std;
long long solve2(long long a[], int n, int k){
    long long left[n + 1], right[n + 1];
    for(int i = 1; i <= n; ++i){
        if(i % k == 1){
            left[i] = a[i];
        }
        else{
            left[i] = __gcd(left[i - 1], a[i]);
        }
    }
    for(int i = n; i >= 1; --i){
        if(i % k == 0 || i == n){
            right[i] = a[i];
        }
        else{
            right[i] = __gcd(right[i + 1], a[i]);
        }
    }
    int l = 1, r = k;
    long long Max = 1;
    while(r <= n){
        if(r % k == 0){
            Max = max(Max, left[r]);
        }
        else{
            Max = max(Max, __gcd(right[l], left[r]));
        }
        l++;
        r++;
    }
    return Max;
int main()
{
	int n, k;
	cin >> n >> k;
	unsigned long long arr[n+1], ans[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i <= n - k; i++) {

		// Store GCD of subarray
		unsigned long long gcd = arr[i];

		for (int j = i + 1; j < i + k; j++) {

			// Update GCD of subarray
			gcd = __gcd(gcd, arr[j]);
		}

		// Print GCD of subarray
		ans[i] = gcd;
	}
	cout << max_element(ans, ans+n);
}
