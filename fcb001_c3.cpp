#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    vector<int> a(n + 1);
    map<int, int> mapp;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        mapp[a[i] * a[i]] += 1;
    }
    int count = 0;
    for(int i = 1; i <= n; i++) {
        count += mapp[k - a[i]];
    }
    cout << count;
}