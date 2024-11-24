#include <iostream>
#include <algorithm>
int a[10000005];
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;


    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        a[i] = count(s.begin(), s.end(), '3');
    }

    long long ans = 0, curr = 0, j = 1;
    for (int i = 1; i <= n; ++i) {
        curr += a[i];
        while (curr >= k) {
            curr -= a[j];
            ++j;
        }
        if (i >= j) {
            ans += i - j + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
