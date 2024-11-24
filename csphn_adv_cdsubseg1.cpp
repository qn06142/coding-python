#include<bits/stdc++.h>
using namespace std;
#define int long long
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

int rangeGCD(vector<int>& segTree, int pos, int left, int right, int qLeft, int qRight) {
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

int maxLengthGCDSubarray(const vector<int>& A, int n) {
    if (n == 0) return 0;

    int segTreeSize = 4 * pow(2, ceil(log2(n)));
    vector<int> segTree(segTreeSize);
    buildSegmentTree(segTree, A, 0, 0, n - 1);

    int l = 0, r = 0, maxLen = 0;
    while (r < n and l < n) {
        if (rangeGCD(segTree, 0, 0, n - 1, l, r) == 1) {
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }

    return maxLen;
}

signed main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            A[i] = abs(A[i]);
        }
        cout << maxLengthGCDSubarray(A, n) << endl;
    }
    return 0;
}
