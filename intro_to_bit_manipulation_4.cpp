#include <iostream>
using namespace std;
#pragma GCC target("bmi")
int main() {
    int q;
    cin >> q;
    int a = 0;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            a = a ^ x;
        } 
        else if (type == 2) {
            if (a != 0) {
                int msb = 1 << (31 - __builtin_clz(a));
                a ^= msb;
            }
        } 
        else if (type == 3) {
            cout << __builtin_popcount(a) << endl; 
        }
    }

    return 0;
}
