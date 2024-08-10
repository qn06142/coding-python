#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int maxLength = 0;

    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> subseq;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subseq.push_back(a[i]);
                sum += a[i];
            }
        }

        bool isIncreasing = true;
        for (int i = 1; i < subseq.size(); ++i) {
            if (subseq[i] <= subseq[i-1]) {
                isIncreasing = false;
                break;
            }
        }

        if (isIncreasing && sum <= W) {
            maxLength = max(maxLength, (int)subseq.size());
        }
    }

    cout << maxLength << endl;
    return 0;
}