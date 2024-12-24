#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn = 25;
ll n, m, len, x, ans = 0;
vector<ll> v;
vector< pair<ll, ll> > w;
pair<ll, ll> p;

void backtrack1(ll i, string s){
	if(i > (len + 1) / 2){
		for(int j = (len + 1) / 2; j < len; ++j) s += s[len - j - 1];
		stringstream cnv;
		cnv << s << endl;
		cnv >> x;
		v.push_back(x);
		return;
	}
	string temp;
	for(int j = '0'; j <= '9'; ++j){
		temp = s;
		temp += j;
		backtrack1(i + 1, temp);
	} 
	return;
}

void backtrack2(ll i, string s){
	if(i > (len + 1) / 2){
		for(int j = (len + 1) / 2; j < len; ++j) s += s[len - j - 1];
		stringstream cnv;
		cnv << s << endl;
		cnv >> x;
		w.push_back({x % m, x});
		return;
	}
	string temp;
	for(int j = '0'; j <= '9'; ++j){
		temp = s;
		temp += j;
		backtrack2(i + 1, temp);
	} 
	return;
}

void solve(){
	cin >> n >> m;
	len = n / 2;
	for(char i = '1'; i <= '9'; ++i){
		string temp = "";
		temp += i;
		backtrack1(2, temp);
	} 
	backtrack2(1, "");
	x = 1;
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	//for(auto h : w) cout << h.first << " " << h.second << "\n";
	for(int i = 1; i <= n / 2; ++i) x *= 10;
	for(auto h : v){
		len = x * h;
		len %= m;
		p  = {(m - len) % m, 0};
		ll i1 = lower_bound(w.begin(), w.end(), p) - w.begin();
		ll i2 = upper_bound(w.begin(), w.end(), p) - w.begin();
		ans += i2 - i1;
		//cout << h << " " << i1 << " " << i2 << "\nx: ";
		//for(int i = i1; i < i2; ++i) cout << w[i].second << " ";
		//cout << "\n";
//		cout << ans << "\n";
	}
	cout << ans;
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen(".INP", "r", stdin);
	//freopen(".OUT", "w", stdout);
	int testCase = 1;
	//cin >> testCase;
	while(testCase--) solve();
}