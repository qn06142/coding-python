#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {

            unsigned long long x, y;
            cin >> x >> y;
            cout << (x & y) << "\n";
        }
        else if (type == 2) {

            unsigned long long x, y;
            cin >> x >> y;
            cout << (x | y) << "\n";
        }
        else if (type == 3) {

            unsigned long long x, y;
            cin >> x >> y;
            cout << (x ^ y) << "\n";
        }
        else if (type == 4) {

            unsigned long long x;
            int y;
            cin >> x >> y;
            cout << (x << y) << "\n";
        }
        else if (type == 5) {

            unsigned long long x;
            int y;
            cin >> x >> y;
            cout << (x >> y) << "\n";
        }
        else if (type == 6) {

            unsigned long long x;
            int y;
            cin >> x >> y;
            cout << ((x >> y) & 1ULL) << "\n";
        }
        else if (type == 7) {

            unsigned long long x;
            int i, v;
            cin >> x >> i >> v;
            if((x>>i&1ll) != v)x ^= (1ll<<i);
            cout << x << "\n";
        }
    }
    return 0;
}