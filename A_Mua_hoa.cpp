#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        long long A, B;
        cin >> A >> B;

        long long power_of_ten = 1;

        while (true) {

            long long low = B * power_of_ten;             
            long long high = (B + 1) * power_of_ten - 1;  

            if (low % A != 0) {
                low += A - (low % A);
            }

            if (low <= high) {
                cout << low << "\n";
                break;
            }

            power_of_ten *= 10;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}