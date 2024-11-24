#include<bits/stdc++.h>

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if(n > 60) {
            n %= 60;
            if(n < 10)
                cout << "09:" << 0 << n;
            else cout << "09:" << n;
        } else {
            if(n < 10)
                cout << "08:" << 0 << n;
            else cout << "08:" << n;
        }
    }
}