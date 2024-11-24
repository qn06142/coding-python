#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    long long a = 0, b = 0;
    for (int i = 1; i <= n; i += 2*k) {
        int a_end = min(i + k - 1, n);
        a += ((long long)(a_end - i + 1) * (i + a_end)) / 2;
        if (a_end < n) {
            int b_start = a_end + 1;
            int b_end = min(b_start + k - 1, n);
            b += ((long long)(b_end - b_start + 1) * (b_start + b_end)) / 2;
        }
    }
    cout << b - a << "\n";
    return 0;
}
