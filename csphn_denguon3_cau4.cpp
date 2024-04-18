#include<iostream>

using namespace std;
int a[(int) 1e5 + 5];
bool check(int k, int x, int n) {
    int curr = x;
    for(int i = 1; i <= n; i++) {
        if(curr - a[i] <= 0) {
            curr = x;
            k -= 1;
        if(k <= 0) {
            return false;
        }
        }
    }
    return true;
}
int main() {
    int k;
    int n;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = n;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(!check(k, mid, n)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l + 4;
}