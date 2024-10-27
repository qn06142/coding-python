#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, K, P;
vector<int> arr, onesCount;
int offset = 0;  // Tracks the virtual rotation offset

// Segment Tree to store the count of `1`s in each K-length subarray
class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) : n(size) {
        tree.assign(4 * size, 0);
    }

    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void build(const vector<int>& data) {
        build(data, 0, 0, n - 1);
    }

    int query(int l, int r, int node, int start, int end) {
        if (r < start || l > end) {
            return 0;  // Out of range
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftQuery = query(l, r, 2 * node + 1, start, mid);
        int rightQuery = query(l, r, 2 * node + 2, mid + 1, end);
        return max(leftQuery, rightQuery);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, n - 1);
    }
};

// Helper function to count `1`s in each K-length subarray
vector<int> computeOnesCount(const vector<int>& arr, int K) {
    int n = arr.size();
    vector<int> count(n - K + 1, 0);
    int currentCount = 0;

    for (int i = 0; i < K; ++i) {
        currentCount += arr[i];
    }
    count[0] = currentCount;

    for (int i = 1; i <= n - K; ++i) {
        currentCount = currentCount - arr[i - 1] + arr[i + K - 1];
        count[i] = currentCount;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> P;
    arr.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    string queries;
    cin >> queries;

    // Compute initial ones count in each K-length subarray and build the segment tree
    onesCount = computeOnesCount(arr, K);
    SegmentTree segTree(N - K + 1);
    segTree.build(onesCount);

    for (char q : queries) {
        if (q == '!') {
            // Type 1 query: Rotate array
            offset = (offset - 1 + N) % N;
        } else if (q == '?') {
            // Type 2 query: Find max ones in a K-length subarray
            int maxOnes = 0;

            // Adjust indices by the offset
            int startIdx = offset % N;
            int endIdx = (startIdx + N - K) % N;

            if (startIdx <= endIdx) {
                // Query within the bounds
                maxOnes = segTree.query(startIdx, endIdx);
            } else {
                // Wrap-around case: query two segments
                maxOnes = max(segTree.query(startIdx, N - 1), segTree.query(0, endIdx));
            }

            cout << maxOnes << "\n";
        }
    }

    return 0;
}
