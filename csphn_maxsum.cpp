#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateSubsetSums(const vector<int>& arr, vector<int>& subsetSums, int m) {
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum = (sum + arr[i]) % m;
            }
        }
        subsetSums.push_back(sum);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int mid = n / 2;
    vector<int> left(a.begin(), a.begin() + mid);
    vector<int> right(a.begin() + mid, a.end());

    vector<int> leftSums, rightSums;
    generateSubsetSums(left, leftSums, m);
    generateSubsetSums(right, rightSums, m);

    sort(rightSums.begin(), rightSums.end());

    int ans = 0;
    for (int lSum : leftSums) {

        int target = m - lSum - 1;
        auto it = upper_bound(rightSums.begin(), rightSums.end(), target);

        if (it != rightSums.begin()) {
            --it;
            ans = max(ans, (lSum + *it) % m);
        }

        ans = max(ans, lSum);
    }

    cout << ans << endl;

    return 0;
}