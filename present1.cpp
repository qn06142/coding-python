#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int ans = 0;
    for(int mid = n; mid >= 0; mid--) {
        vector<int> a_temp(a.begin(), a.begin() + mid);
        vector<int> b_temp(b.begin(), b.begin() + mid);

        sort(a_temp.begin(), a_temp.end());
        sort(b_temp.begin(), b_temp.end());

        bool valid = true;
        for (int i = 0; i < mid; ++i) {
            if (b_temp[i] > a_temp[i]) { 
                valid = false;
                break;
            }
        }

        if (valid) {
            ans = mid;
            break;
        } 
    }

    cout << ans << '\n';
    return 0;
}
