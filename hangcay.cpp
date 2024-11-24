#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("HANGCAY.INP", "r", stdin);
    freopen("HANGCAY.OUT", "w", stdout);
    int n, m;
    cin >> n >> m;

    vector<int> pref(n + 2, 0);

    for (int i = 0; i < m; ++i) {
        int X_i, R_i;
        cin >> X_i >> R_i;

        int start = max(1, X_i - R_i);
        int end = min(n, X_i + R_i);

        pref[start] += 1;
        if (end + 1 <= n) {
            pref[end + 1] -= 1;
        }
    }

    int count = 0;
    int current = 0;
    for (int i = 1; i <= n; ++i) {
        current += pref[i];
        if (current > 0) {
            ++count;
        }
    }

    cout << count << endl;

    return 0;
}