#include<bits/stdc++.h>

using namespace std;
int a[(int) 2e5 + 5];
map<int, vector<int>> divs2;

void factorize(int x) {
    for(int i = 2; i <= sqrt(x); i++) {
        int cnt = 0;
        while(x % i == 0) {
            cnt++;
            x /= i;
        }
        divs2[i].push_back(cnt);
    }
    if(x > 1) divs2[x].push_back(1);
}
long long findmaxsum(int n, int div) {
    vector<int> a(divs2[div].begin(), divs2[div].end());
    vector<int> L(n + 5), R(n + 5);
    stack<int> stacc;
    for(int i = 0; i < n; i++) {
        while(!stacc.empty() and a[stacc.top()] <= a[i]) {
            L[i] += L[stacc.top()] + 1;
            stacc.pop();
        }
        stacc.push(i);
    }
    while(!stacc.empty()) stacc.pop();
    for(int i = n - 1; i >= 0; i--) {
        while(!stacc.empty() and a[stacc.top()] < a[i]) {
            R[i] += R[stacc.top()] + 1;
            stacc.pop();
        }
        stacc.push(i);
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (L[i] + 1) * (R[i] + 1) * a[i];
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        factorize(a[i]);
    }
    long long ans = 1;
    for(auto i:divs2) {
        ans *= pow(i.first, findmaxsum(n, i.first));
        ans %= (long long) 1e9 + 7;
    }
    cout << ans << endl;
}