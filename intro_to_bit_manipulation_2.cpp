#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        unsigned query_type, x;
        cin >> query_type >> x;

        if (query_type == 1) {

            cout << __builtin_popcount(x) << endl;
        }
        else if (query_type == 2) {

            if (x == 0) {
                cout << -1 << endl;
            } else {
                int highest_bit_position = 31 - __builtin_clz(x); 
                cout << highest_bit_position << endl;
            }
        }
        else if (query_type == 3) {

            if (x == 0) {
                cout << -1 << endl;
            } else {
                int lowest_bit_position = __builtin_ctz(x); 
                cout << lowest_bit_position << endl;
            }
        }
    }

    return 0;
}
