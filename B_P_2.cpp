#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ll long long
#define ar array
#define ld long double
 
const int N = 100;
const int X = 10005;
const int B = 400;
const int M = 200;
const int INF = 1e15;
const int LOG = 63;
const int MOD = 1e9 + 7;
 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,bmi,bmi2,lzcnt,popcnt")
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int f(int h,int w){
	int a = h * (h + 1) / 2;
	a %= MOD;
	int b = w * (w + 1) / 2;
	b %= MOD;
	return (a * b) % MOD;
}
 
stack<ar<int, 2> > s;
 
int ans;
 
void push(int h,int w){
	int sum = 0;
	
	while(s.size() && s.top()[0] > h){
		sum += s.top()[1];
		sum %= MOD;
		ans += f(sum, s.top()[0]);
		ans %= MOD;
		ans -= f(sum - s.top()[1], s.top()[0]);
		ans = (ans % MOD + MOD) % MOD;
		s.pop();
	}
	ans -= f(sum, h);
	ans = (ans % MOD + MOD) % MOD;
	s.push(ar<int, 2>{h, sum + w});
}
 
signed main(){ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	int h[n], w[n];
	for(int i = 0;i < n;i++)cin>>h[i];
	for(int i = 0;i < n;i++)cin>>w[i];
	for(int i = 0;i < n;i++)push(h[i], w[i]);
	push(0, 0);
	cout<<ans;
	
}