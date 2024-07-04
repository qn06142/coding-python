#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
int h[maxn], L[maxn], R[maxn];
int m, n;

int main() {
    cin >> m >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[i] <= a[st.top()]) st.pop();
        if (st.empty()) L[i] = 1; else L[i] = st.top() + 1;
        st.push(i);		
    }
    stack<int> st2;
    for (int i = n; i >= 1; i--) {
        while (!st2.empty() && a[i] <= a[st2.top()]) st2.pop();
        if (st2.empty()) R[i] = n; else R[i] = st2.top() - 1;
        st2.push(i);
    }
    long long ans = INT_MIN;
    for (int i = 1; i <= n; i++)  ans = max(ans, 1LL * a[i] * (R[i] - L[i] + 1));
    for (int i = 1; i <= n; i++) {
        a[i] = m - a[i];
    }
    while(!st.empty()) st.pop();
    while(!st2.empty()) st2.pop();
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[i] <= a[st.top()]) st.pop();
        if (st.empty()) L[i] = 1; else L[i] = st.top() + 1;
        st.push(i);		
    }
    for (int i = n; i >= 1; i--) {
        while (!st2.empty() && a[i] <= a[st2.top()]) st2.pop();
        if (st2.empty()) R[i] = n; else R[i] = st2.top() - 1;
        st2.push(i);
    }
    for (int i = 1; i <= n; i++)  ans = max(ans, 1LL * a[i] * (R[i] - L[i] + 1));



    cout << ans << endl;
    return 0;
}