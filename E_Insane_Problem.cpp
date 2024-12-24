#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        long long k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        long long count = 0;
        long long power = 1; 

        while (power <= r2) {

            long long lx = max(l1, (l2 + power - 1) / power); 
            long long rx = min(r1, r2 / power);

            if (lx <= rx) {
                count += (rx - lx + 1);
            }

            if (power > r2 / k) break; 
            power *= k;
        }

        cout << count << "\n";
    }

    return 0;
}