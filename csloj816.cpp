#include<bits/stdc++.h>

using namespace std;

int a[(int) 3e5 + 5];
long long pref[(int) 3e5 + 5];
long long prefme[(int) 3e5 + 5], prefmo[(int) 3e5 + 5];

signed main() {
    int n;
    cin >> n;
    pref[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i += 2) {
        prefmo[i] = min(prefmo[i - 2], pref[i]);
        prefme[i + 1] = min(prefme[i - 1], pref[i + 1]);
    }
    vector<long long> yes;
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) {
            yes.push_back(pref[i] - prefme[i - 4]);
        } else {
            yes.push_back(pref[i] - prefmo[i - 4]);
        }
    }
    cout << *max_element(yes.begin(), yes.end());
}