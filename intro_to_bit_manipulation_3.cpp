#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b, c = 0;
        cin >> a >> b;
        for (int i = 0; i < 15; ++i) {
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            int bit_c;
            if (i <= 4) {
                bit_c = bit_a ^ bit_b;
            } else if (i <= 9) {
                bit_c = bit_a & bit_b;
            } else {
                bit_c = bit_a | bit_b;
            }
            c |= (bit_c << i);
        }
        cout << c << endl;
    }
    return 0;
}
