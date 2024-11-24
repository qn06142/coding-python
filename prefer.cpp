#include<iostream>
#include<algorithms>
using namespace std;
int a[(int) 1e5 + 5];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << upper_bound(a, a + n, l) - lower_bound(a, a + n, r);
    }
}