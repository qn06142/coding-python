#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//khởi động lại đã.

stack<ll> u, v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll k, res = 0; string n; cin >> k >> n;
    for(ll i = 0; i <= n.size() - 1; i++) {
        while(!u.empty() && u.top() < (n[i] - '0')) {
            u.pop();
            k--;
        }
        u.push(n[i] - '0');
    }
    while(k) {
        u.pop();
        k--;
    }
    while(!u.empty()) {
        u.pop();
    }
    while(!v.empty()) {
        res = 10 * res + v.top();
        v.pop();
    }
    cout << res;
}