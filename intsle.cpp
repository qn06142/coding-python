#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while(ntest--) {
        long long a1, b1, c1, a2, b2, c2;

        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

        long long d = a1 * b2 - a2 * b1;
        long long dx = c1 * b2 - c2 * b1;
        long long dy = a1 * c2 - a2 * c1;

        if(d == 0 && (dx != 0 || dy != 0)) {
            cout << "NO SOLUTION\n";
        }
        else if(d == 0 && dx == 0 && dy == 0) {
            int t = __gcd(a1, b1);
            int t2 = __gcd(a2, b2);
            if(t != 0 && c1 % t == 0) cout << "INFINITE\n";
            else if(t2 != 0 && c2 % t2 == 0) cout << "INFINITE\n";
            else if(t == 0 && t2 == 0 && c1 == 0 && c2 == 0) cout << "INFINITE\n";
            else cout << "NO SOLUTION\n";
        }
        else {
            if(dx % d == 0 && dy % d == 0) {
                cout << dx / d << " " << dy / d << "\n";
            }
            else {
                cout << "NO SOLUTION\n";
            }
        }
    }
    return 0;
} 