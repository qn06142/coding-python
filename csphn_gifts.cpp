#include<iostream>
#include<vector>

using namespace std;
int a[(int) 1e6 + 5], pref[(int) 1e6 + 5];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] + = 
    }
    int ans = 1e9;
    for(int i = 1; i <= n - k; i++) {
        int tmp = 0;
        for(int j = 1; j <= n - k; j++) {
            if(i >= j + k) {
                tmp = max(tmp, pref[])
            }
            if(i + k >= j) {

            }
        }
        ans = min(ans, tmp1);
    }
    cout << ans;
}