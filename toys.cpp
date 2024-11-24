#include <iostream>
#include <vector>
using namespace std;

int main() {
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, v, l, r;
    cin >> n >> v >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long count = 0;
    long long sum = 0;
    int i = 0;

    for (int j = 0; j < n; ++j) {
        sum += a[j]; 
        while (sum > v) {
            sum -= a[i]; 
            ++i;
        }

        if (j - i + 1 >= l) {
            count += min(j - i + 1, r) - l + 1;
        }
    }

    cout << count << '\n';
    return 0;
}