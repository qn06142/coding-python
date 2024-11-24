#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> lis, idx(n), prev(n, -1);
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        int pos = it - lis.begin();
        if (it == lis.end()) lis.push_back(a[i]);
        else *it = a[i];
        idx[pos] = i;
        if (pos > 0) prev[i] = idx[pos - 1];
    }

    int m = lis.size();
    cout << m << "\n";
    vector<int> seq(m);
    for (int i = idx[m - 1]; i != -1; i = prev[i]) seq[--m] = a[i];
    for (int x : seq) cout << x << " ";
    cout << "\n";

    return 0;
}
