#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

void buildSegmentTree(vector<int>& segTree, const vector<int>& arr, int pos, int left, int right) {
    if (left == right) {
        segTree[pos] = arr[left];
    } else {
        int mid = (left + right) / 2;
        buildSegmentTree(segTree, arr, 2 * pos + 1, left, mid);
        buildSegmentTree(segTree, arr, 2 * pos + 2, mid + 1, right);
        segTree[pos] = gcd(segTree[2 * pos + 1], segTree[2 * pos + 2]);
    }
}

int rangeGCD(const vector<int>& segTree, int pos, int left, int right, int qLeft, int qRight) {
    if (qLeft > right || qRight < left) {
        return 0; 
    }
    if (qLeft <= left && qRight >= right) {
        return segTree[pos];
    }
    int mid = (left + right) / 2;
    return gcd(rangeGCD(segTree, 2 * pos + 1, left, mid, qLeft, qRight),
               rangeGCD(segTree, 2 * pos + 2, mid + 1, right, qLeft, qRight));
}

bool check(const vector<int>& segTree, int n, int len) {
    for (int i = 0; i <= n - len; i++) {
        if (rangeGCD(segTree, 0, 0, n - 1, i, i + len - 1) > 1) {
            return true;
        }
    }
    return false;
}

int maxLengthGCDSubarray(const vector<int>& A, int n) {
    if (n == 0) return 0;

    int segTreeSize = 2 * pow(2, ceil(log2(n))) - 1;
    vector<int> segTree(segTreeSize);
    buildSegmentTree(segTree, A, 0, 0, n - 1);

    int l = 1, r = n, maxLen = 0; 
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(segTree, n, mid)) {
            maxLen = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return maxLen;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        cout << maxLengthGCDSubarray(A, n) << endl;
    }
    return 0;
}