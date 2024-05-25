#include<iostream>
#include<map>
#include<numeric>
#include<algorithm>
using namespace std;
int a[(int) 1e3 + 5], f[(int) 3e5 + 5];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i <  (int) 3e5 +5; i++) {
        for(int j = i; j <= (int) 3e5 +5; j += i) {
            f[j] ++;
        }
    }

    long long ans = 0;
    for (int x = 0; x < n; x++)
        for (int y = x; y < n; y++) {
            int d = m;
            d /= __gcd(a[x], d);
            d /= __gcd(a[y], d);
            ans += f[d];
        }

    cout << ans << endl;

    return 0;
}
