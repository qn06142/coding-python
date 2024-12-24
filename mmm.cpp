#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void computeSubsetSums(const vector<int>& arr, vector<int>& subsetSums, int M) {
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        subsetSums.push_back(sum % M);
    }
}

int main() {

    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int mid = n / 2;
    vector<int> left(a.begin(), a.begin() + mid);
    vector<int> right(a.begin() + mid, a.end());

    vector<int> leftSums, rightSums;
    computeSubsetSums(left, leftSums, M);
    computeSubsetSums(right, rightSums, M);

    sort(leftSums.begin(), leftSums.end());

    int maxModSum = 0;
    for (int x : rightSums) {

        int target = M - 1 - x;
        auto it = upper_bound(leftSums.begin(), leftSums.end(), target);
        if (it != leftSums.begin()) {
            --it;
            maxModSum = max(maxModSum, (x + *it) % M);
        }

        maxModSum = max(maxModSum, x % M);
    }

    cout << maxModSum << endl;

    return 0;
}