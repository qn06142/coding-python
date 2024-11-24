#include <bits/stdc++.h>
using namespace std;
#define maxN 1000
#define maxM 1000

// Function to return the length of the longest subsequence
// whose sum is divisible by m
int findLen(int* arr, int n, int m)
{
	// To store the states of DP
	vector<int> dp(maxM),new_dp(maxM);

	// Initialize the DP array
	for (int curr = 0; curr < m; ++curr) {
		dp[curr] = -1;
	}
	dp[0] = 0;

	// Tabulation with space optimization
	for (int i = n-1; i >=0; --i) {
		// compute new_dp from prev dp 
		new_dp=dp;
		for (int curr = 0; curr < m; ++curr) {
			// Recurrence relation
			int l = dp[curr];// not pick
			int r = dp[(curr - arr[i] + m) % m]; // pick
			new_dp[curr] = l;
			if (r != -1)
				new_dp[curr] = max(new_dp[curr], r + 1);
		}
		// use new_dp as prev dp
		// to compute next states
		dp=new_dp;
	}

	if (dp[0] == -1)
		return 0;
	else
		return dp[0];
}

// Driver code
int main()
{
	int m, n;
	cin >> n >> m;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << findLen(arr, n, m);

	return 0;
}
