#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    
    unsigned int x = 0;
    while (q--) {
        int type, k;
        cin >> type >> k;
        
        if (type == 1) {
            x |= (1 << k);
        } else if (type == 2) {
            x &= ~(1 << k);
        } else if (type == 3) {
            x ^= (1 << k);
        }
        
        cout << x << '\n';
    }
    
    return 0;
}
