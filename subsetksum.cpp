#include<bits/stdc++.h>
using namespace std;
int a[(int) 1e6 + 5];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int curr = 0, l = 0, r = 0, count = 0;
    while (r < n) {
        curr += a[r];
        while (curr > k) {
            curr -= a[l];
            l++;
        }
        count += r - l + 1;
        r++;
    }
    cout << count;
}
