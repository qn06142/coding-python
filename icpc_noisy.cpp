#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
long long a[maxn];
long long pref[maxn];
long long suf[maxn];
map<long long, set<long long>> stor;
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n ;i++) {
        cin >> a[i];
    }
    pref[0] = 1;
    for(int i = 1; i <= n ;i++) {
        pref[i] = pref[i - 1] * a[i];
    }

    suf[n + 1] = 1;
    for(int i = n; i >= 1 ;i--) {
        suf[i] = suf[i + 1] * a[i];
    }

    for(int i = 1; i <= n; i++) {
        stor[suf[i + 1] * pref[i - 1]].insert(a[i]);
    }
    cout << *stor.rbegin()->second.begin() << ' ' << *stor.rbegin()->second.rbegin();
}