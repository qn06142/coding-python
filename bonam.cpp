#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, w1, w2;
    cin >> n >> w1 >> w2;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> prefix_w1(n + 1, LLONG_MIN); 
    vector<int> prefix_w2(n + 1, LLONG_MIN); 
    vector<int> suffix_w2(n + 2, LLONG_MIN); 
    vector<int> suffix_w1(n + 2, LLONG_MIN); 

    for (int i = 1; i <= n; ++i) {
        prefix_w1[i] = max(prefix_w1[i - 1], w1 * a[i]);
        prefix_w2[i] = max(prefix_w2[i - 1], w2 * a[i]);
    }

    for (int i = n; i >= 1; --i) {
        suffix_w2[i] = max(suffix_w2[i + 1], w2 * a[i]);
        suffix_w1[i] = max(suffix_w1[i + 1], w1 * a[i]);
    }

    int result = LLONG_MIN;

    for (int i = 3; i <= n - 2; ++i) {
        int left1 = prefix_w1[i - 2];
        int left2 = prefix_w2[i - 1];
        int right1 = suffix_w2[i + 1];
        int right2 = suffix_w1[i + 2];

        // Ensure no overlaps in indices
        if (i - 2 >= 1 && i - 1 >= 1 && i + 1 <= n && i + 2 <= n) {
            int weight = left1 + left2 + w1 * a[i] + right1 + right2;
            result = max(result, weight);
        }
    }

    cout << result << "\n";

    return 0;
}
