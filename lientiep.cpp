#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);

    for (int &d : a) cin >> d;

    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

    int max_length = 0;
    for (int d : a) {
        int length = upper_bound(a.begin(), a.end(), d + n - 1) - lower_bound(a.begin(), a.end(), d);
        max_length = max(max_length, length);
    }

    cout << n - max_length;
    return 0;
}
