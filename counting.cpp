#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int f[17] = {0, 3, 6, 22, 68, 217, 683, 2163, 6837, 21623, 68377, 216228, 683772, 2162278, 6837722, 21622777, 68377224};
ull p10(int n) {
    if (n == 0) return 1;
    ull res = 1;
    for (int i = 1; i <= n; i++) res *= 10;
    return res;
}
int main() {
    int k, n = 1;
    cin >> k;
    while (k >= n*f[n]) {
        k -= n*f[n];
        n++;
    }
    if (k == 0)
        cout << ((ull)(sqrt(p10(n - 1) - 1))*(ull)(sqrt(p10(n - 1) - 1))) % 10; 
    else if (k % n == 0) cout << to_string((ceil(sqrt(p10(n - 1))) + k / n - 1)*(ceil(sqrt(p10(n - 1))) + k / n - 1))[n - 1];
    else cout << to_string((ceil(sqrt(p10(n - 1))) + k / n)*(ceil(sqrt(p10(n - 1))) + k / n))[k % n - 1];
    return 0;
}