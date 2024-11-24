#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main() {
    int n, H;
    cin >> n >> H;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_fruits = 0;
    int max_distance = H / 3;  

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = max(0LL, i - max_distance); j <= min(n - 1, i + max_distance); j++) {
            sum += a[j];
        }

        max_fruits = max(max_fruits, sum);
    }

    cout << max_fruits << endl;

    return 0;
}