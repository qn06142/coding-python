#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int nim_sum = 0;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        
        int g;
        if (n >= 2) {
            g = y - 1;
        } else {
            g = (y - 1) % 2;
        }
        
        nim_sum ^= g;
    }
    
    if (nim_sum != 0) {
        cout << "Mimo\n";
    } else {
        cout << "Yuyu\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}