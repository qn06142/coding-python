#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 5;
int a[maxn], h[maxn], l[maxn], r[maxn], ans = INT_MIN, m, n;
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int i = 1; i <= m; i++) cin >> a[i];
        for(int i = 1; i <= m; i++) {
            h[i] = a[i] == 1 ? h[i] + 1 : 0;
        }
        stack<int> stacc;
        while(!stacc.empty()) stacc.pop();

        for(int i = 1; i <= m; i++) {
            while(!stacc.empty() and h[i] <= h[stacc.top()]) {
                stacc.pop();
            }
            l[i] = stacc.empty() ? 1 : stacc.top() + 1;
            stacc.push(i);
        }
        while(!stacc.empty()) stacc.pop();

        for(int i = m; i >= 1; i--) {
            while(!stacc.empty() and h[i] <= h[stacc.top()]) {
                stacc.pop();
            }
            r[i] = stacc.empty() ? m : stacc.top() - 1;
            stacc.push(i);
        }
        for(int i = 1; i <= m; i++) {ans = max(ans, h[i] * (r[i] - l[i] + 1));}
    }
    cout << ans;
}