#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 1 << 23;
int segtree[2 * MAXN];

void update(int node, int start, int end, int idx) {
    if (start == end) {
        segtree[node] += 1;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx);
        } else {
            update(2 * node + 1, mid + 1, end, idx);
        }
        segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
    }
}

int query(int node, int start, int end, int L, int R) {
    if (R < start or end < L) {
        return 0;
    }
    if (L <= start and end <= R) {
        return segtree[node];
    }
    int mid = (start + end) / 2;
    int left = query(2 * node, start, mid, L, R);
    int right = query(2 * node + 1, mid + 1, end, L, R);
    return left + right;
}

int main() {
    int n;
    cin >> n;
    vector<int> power(n);
    map<int, int> compress;
    vector<int> compressed_power(n);

    for (int i = 0; i < n; i++) {
        cin >> power[i];
        compress[power[i]];
    }

    int idx = 0;
    for (auto& it : compress) {
        it.second = idx++;
    }

    for (int i = 0; i < n; i++) {
        compressed_power[i] = compress[power[i]];
    }

    vector<int> gr(n), le(n);

    for (int i = 0; i < n; i++) {
        gr[i] = query(1, 0, n - 1, compressed_power[i] + 1, n - 1);
        update(1, 0, n - 1, compressed_power[i]);
    }

    fill(segtree, segtree + 2 * MAXN, 0);

    for (int i = n - 1; i >= 0; i--) {
        le[i] = query(1, 0, n - 1, 0, compressed_power[i] - 1);
        update(1, 0, n - 1, compressed_power[i]);
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += 1LL * le[i] * gr[i];
    }

    cout << result << endl;

    return 0;
}