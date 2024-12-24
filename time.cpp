#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if(n >= 60) {
            n %= 60;
            if(n < 10)
                cout << "09:" << 0 << n;
            else cout << "09:" << n;
        } else {
            n %= 60;
            if(n < 10)
                cout << "08:" << 0 << n;
            else cout << "08:" << n;
        }
        cout << '\n';
    }
}