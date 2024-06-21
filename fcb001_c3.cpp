#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int count = 0;
    map<int, int> mapp;
    for(int j = 1; j <= n; j++) {
        int aj2 = a[j] * a[j];
        if (mapp.find(k - aj2) != mapp.end()) {
            count += mapp[k - aj2];
        }
        mapp[a[j]]++;
    }

    cout << count;
    return 0;
}