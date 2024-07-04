#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 7;

int a[N], n, pos_max[N], pos_min[N];
typedef long long ll;
ll f[N], g[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    stack<int> st;
    for(int i = 1; i <= n; i++) {
        while (!st.empty() && a[i] > a[st.top()]) st.pop();
        if (st.empty()) pos_max[i] = 0; else pos_max[i] = st.top();
        st.push(i);
    }
    stack<int> st2;
    for(int i = 1; i <= n; i++) {
        while (!st2.empty() && a[i] < a[st2.top()]) st2.pop();
        if (st2.empty()) pos_min[i] = 0; else pos_min[i] = st2.top();
        st2.push(i);
    }
    for(int i = 1; i <= n; i++) {
        f[i] = 1LL * a[i] * (i - pos_max[i]) + f[pos_max[i]];
        g[i] = 1LL * a[i] * (i - pos_min[i]) + g[pos_min[i]];
    }
    ll res = 0;
    for(int i = 1; i <= n; i++) res+=f[i] - g[i];
    cout<<res;
    return 0;
}
