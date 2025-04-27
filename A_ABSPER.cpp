#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n, k;
        cin >> n >> k;
        
        if (k == 0) {
            for (int i = 1; i <= n; ++i) {
                cout << i << " ";
            }
            cout << "\n";
        } else if (n % (2 * k) != 0) {
            cout << "-1\n";
        } else {
            for (int i = 1; i <= n; ++i) {
                if ((i - 1) / k % 2 == 0) {
                    cout << i + k << " ";
                } else {
                    cout << i - k << " ";
                }
            }
            cout << "\n";
        }
    }
    
    return 0;
}
