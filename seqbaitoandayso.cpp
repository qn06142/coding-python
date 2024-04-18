#include<iostream>
#include<numeric>
using namespace std;
int a[(int) 5e4 + 5];
int pref[(int) 5e4 + 5];
int calc(int n, int l, int r) {
    if(l >= r) return 0;
    for(int i = l; i < r; i++) {
        if(pref[i] - pref[l - 1] == pref[r] - pref[i]) {
            return max(calc(n, l, i), calc(n, i + 1, r)) + 1;
        }
    }
    return 0;
}
int main() {
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }
        cout << calc(n, 1, n) << "\n";
    }
}
