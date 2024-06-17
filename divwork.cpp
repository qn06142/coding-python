#include<bits/stdc++.h>

using namespace std;
int pref1[(int) 2e5 + 5], pref2[(int) 2e5 + 5], a[(int) 2e5 + 5], b[(int) 2e5 + 5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n + 1; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) cin >> b[i];
    sort(a + 1, a + 2 + n);
    sort(b + 1, b + 1 + n);
    // calculate prefix sums from left to right
    for(int i = 1; i <= n; i++) {
        pref1[i] = max(pref1[i - 1], max(a[i] - b[i], 0));
    }
    
    // calculate prefix sums from right to left
    for(int i = n; i >= 1; i--) {
        pref2[i] = max(pref2[i + 1], max(a[i + 1] - b[i], 0));
    }
    
    // output the minimum wasted time if task k is dropped
    for(int i = 1; i <= n + 1; i++) {
        if(i == 1) {
            cout << pref2[1] << ' ';
        } else if(i == n + 1) {
            cout << pref1[n] << ' ';
        } else {
            cout << max(pref1[i - 1], pref2[i]) << ' ';
        }
    }
}
