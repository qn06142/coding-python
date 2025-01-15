#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
    for (int i = 1; i <= n; ++i) b[i] += b[i - 1];

    vector<vector<long long>> matrix(n + 1, vector<long long>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {

            matrix[i][j] = a[j] - a[i - 1];
        }
        for (int j = i - 1; j >= 1; --j) {

            matrix[i][j] = b[i] - b[j - 1];
        }
    }
    vector<vector<long long>> pref(n + 1, vector<long long>(n + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            pref[i][j] = pref[i - 1][j] + matrix[i][j];
        }
    }
    long long maxSum = LLONG_MIN;

    for (int row1 = 1; row1 <= n; ++row1) {
        for (int row2 = row1; row2 <= n; ++row2) {
            vector<long long> st(n + 2);
            for(int i = 1; i <= n; i++) {
                st[i] = pref[row2][i] - pref[row1 - 1][i] + st[i - 1];
            }
            long long ans = LLONG_MIN;
            long long minpref = 0;
            for(int i = 1; i <= n; i++) {
                ans = max(ans, st[i] - minpref);
                minpref = min(minpref, st[i]);
            }
            maxSum = max(maxSum, ans);
        }
    }

    cout << maxSum << endl;

    return 0;
}