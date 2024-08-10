#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        long long count = 0;
        
        for (int a = 1; a <= x - 2 && a * a <= n; ++a) {
            for (int b = 1; b <= x - a - 1 && a * b <= n; ++b) {
                // Calculate the maximum possible value of c
                int max_c = min(x - a - b, n / (a + b));
                count += max(0, max_c);
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
