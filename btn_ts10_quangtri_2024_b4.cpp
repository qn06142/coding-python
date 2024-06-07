#include<iostream>

using namespace std;
int f[20][20], n, x;
long long ans = 0;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        int dv = 1;
        while(x > 0) {
            ans += (long long) f[dv][x % 10];
            f[dv][x % 10]++;
            dv++;
            x /= 10;
        }
    }
    cout << ans;
}