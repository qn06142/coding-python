#include <iostream>
#include <map>
using namespace std;
#define int long long
int a[(int)5e5 + 5];
int freq[(int)5e5 + 5];

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, count = 0;
    for (int r = 1; r <= n; r++) {
        freq[a[r]] += 1;
        while (freq[a[r]] > 2) {
            freq[a[l]] -= 1;
            l += 1;
        }
        count += r - l + 1;
    }
    cout << count << endl;
    return 0;
}
