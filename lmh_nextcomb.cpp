#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) cin >> a[i];

    int pos = -1;
    for (int i = k - 1; i >= 0; --i) {
        int max_i = n - (k - 1 - i); // = n - k + i + 1
        if (a[i] < max_i) { pos = i; break; }
    }

    if (pos == -1) {
        cout << "NOTAVAILABLE\n";
        return 0;
    }

    // increment at pos and fill suffix
    a[pos] += 1;
    for (int j = pos + 1; j < k; ++j) a[j] = a[j - 1] + 1;

    for (int i = 0; i < k; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}
