#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
        int max_revenue = 0;
        for (int i = 0; i < n; ++i) {
            int price = a[i];
            int revenue = price * (n - i);
            max_revenue = max(max_revenue, revenue);
        }
        
        cout << max_revenue << endl;
    }
    return 0;
}
