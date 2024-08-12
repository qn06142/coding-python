#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    // Sort the array to apply two-pointer technique
    sort(a.begin(), a.end());
    
    vector<int> freq(m + 1, 0);
    int count = 0;
    
    int l = 0, r = 0, min_diff = INT_MAX;
    
    while (r < n) {
        // Add the rightmost element to the team and update frequency/count
        for (int j = 1; j * j <= a[r]; ++j) {
            if (a[r] % j == 0) {
                if (j <= m) {
                    if (++freq[j] == 1) count++;
                }
                int div = a[r] / j;
                if (div <= m && div != j) {
                    if (++freq[div] == 1) count++;
                }
            }
        }
        
        // Check if the team is proficient
        while (count == m) {
            min_diff = min(min_diff, a[r] - a[l]);
            
            // Remove the leftmost element from the team and update frequency/count
            for (int j = 1; j * j <= a[l]; ++j) {
                if (a[l] % j == 0) {
                    if (j <= m && --freq[j] == 0) count--;
                    int div = a[l] / j;
                    if (div <= m && div != j && --freq[div] == 0) count--;
                }
            }
            l++;
        }
        
        r++;
    }
    
    cout << (min_diff == INT_MAX ? -1 : min_diff) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
