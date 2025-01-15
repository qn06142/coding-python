#include "bits/stdc++.h"
using namespace std;

#define int long long
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int sz = 320;

int n, d[N], x[N], ends_at[N];
vector<pair<int, int>> v[N];
const int MAX_DIVISOR = 320; 
int dp[N];                  
int grouped_contributions[MAX_DIVISOR + 5][MAX_DIVISOR + 5]; 
int total_ways;             
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("bus.inp", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i] >> x[i];
        ends_at[i] = min(n, i + d[i] * x[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] && d[i] <= sz) {
            v[ends_at[i]].push_back({i, d[i]});
        }
    }

	dp[1] = 1; 

	for (int position = 1; position <= n; position++) {

		for (int divisor = 1; divisor <= MAX_DIVISOR; divisor++) {
			dp[position] = (dp[position] + grouped_contributions[divisor][position % divisor]) % mod;
		}

		if (d[position] > MAX_DIVISOR) {
			for (int next_pos = position + d[position]; next_pos <= ends_at[position]; next_pos += d[position]) {
				dp[next_pos] = (dp[next_pos] + dp[position]) % mod;
			}
		} 

		else if (d[position] > 0) {
			grouped_contributions[d[position]][position % d[position]] = 
				(grouped_contributions[d[position]][position % d[position]] + dp[position]) % mod;
		}

		for (auto [previous_pos, divisor] : v[position]) {
			if (divisor <= MAX_DIVISOR) {
				grouped_contributions[divisor][previous_pos % divisor] = 
					(grouped_contributions[divisor][previous_pos % divisor] - dp[previous_pos] + mod) % mod;
			}
		}
	}

	for (int position = 1; position <= n; position++) {
		total_ways = (total_ways + dp[position]) % mod;
	}

	cout << total_ways;
}
