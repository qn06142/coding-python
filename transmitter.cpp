#include<iostream>
using namespace std;
int a[(int) 1e3 + 5];
int n, k;
int check(int x) {
    int i = 1;
    int t = a[1] + x, t1 = a[2] + x;
    int c = 0, c1 = 0;

    for(int i = 2; i < n; i++) {
        if(a[i] < t + x or a[i] > t - x) continue;
        t = a[i] + x;
        c++;
    }
    if((a[n] > t - x)) c++;
    a[n] = a[1];
    for(int i = 3; i <= n; i++) {
        if(a[i] < t1 + x or a[i] > t1 - x) continue;
        t1 = a[i] + x;
        c1++;
    }
    if(!(a[n + 1] > (a[n] + x) % (int) 1e6)) c1++
    return min(c, c1) <= k;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> k;
    sort(a + 1, a + 1 + n);
    int l = 0, r = 1e9;
    while(l < r) {
        mid = (l + r) / 2;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l;
}