#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int maxn = 2005;
int a[maxn], pref[maxn];

int max_two_subarrays(int n) {

    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }

    vector<int> maxSumEndingBefore(n + 1, INT_MIN);
    vector<int> maxSumStartingAfter(n + 1, INT_MIN);
    vector<int> prefixminsum(n + 5, INT_MAX);
    for (int len = 3; len <= n; len += 3) {
        for (int i = len; i <= n; ++i) {
            int sum = pref[i] - pref[i - len];
            maxSumEndingBefore[i] = max(maxSumEndingBefore[i], sum);
        }
    }

    for (int i = 1; i <= n; ++i) {
        maxSumEndingBefore[i] = max(maxSumEndingBefore[i], maxSumEndingBefore[i - 1]);
    }

    for (int len = 3; len <= n; len += 3) {
        for (int i = n - len + 1; i >= 1; --i) {
            int sum = pref[i + len - 1] - pref[i - 1];
            maxSumStartingAfter[i] = max(maxSumStartingAfter[i], sum);
        }
    }

    for (int i = n - 1; i >= 1; --i) {
        maxSumStartingAfter[i] = max(maxSumStartingAfter[i], maxSumStartingAfter[i + 1]);
    }

    int maxSum = INT_MIN;
    for (int i = 3; i <= n - 3; ++i) {
        if (maxSumEndingBefore[i] != INT_MIN && maxSumStartingAfter[i + 1] != INT_MIN) {
            maxSum = max(maxSum, maxSumEndingBefore[i] + maxSumStartingAfter[i + 1]);
        }
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    cout << max_two_subarrays(n) << endl;

    return 0;
}