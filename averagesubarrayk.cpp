#include<bits/stdc++.h>

using namespace std;
long long a[(int) 1e5 + 5], pref[(int) 1e5 + 5];
int main() {
    #define int long long
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= k;
    }
    map<int, int> mapp;
    int count = 0;
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
        count += mapp[pref[i]];
        if(pref[i] == 0) count += 1;
        mapp[pref[i]] ++;
    }
    cout << count;
}