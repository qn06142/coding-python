#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500005;
int a[MAX_N]; // Mảng chứa số lượng kẹo trong mỗi hộp
int b[MAX_N]; // Mảng chứa độ tế nhị của mỗi bạn
int bit[MAX_N]; // Fenwick Tree để quản lý số lượng kẹo

// Update a Fenwick Tree at a specific index by a delta
void update(int index, int delta, int n) {
    while (index <= n) {
        bit[index] += delta;
        index += index & -index;
    }
}

// Query the sum from start to a specific index in a Fenwick Tree
int query(int index) {
    int sum = 0;
    while (index > 0) {
        sum += bit[index];
        index -= index & -index;
    }
    return sum;
}

// Update the range [l, r] by adding value v
void range_update(int l, int r, int n) {
    update(l, 1, n);
    update(r + 1, -1, n);
}

int find_first_ge(int x, int n) {
    int low = 1, high = n, pos = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if ((a[mid] - query(mid)) >= x) {
            pos = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return pos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> b[i];

    sort(a + 1, a + 1 + n);

    for (int j = 1; j <= m; ++j) {
        int bi = b[j];
        int pos = find_first_ge(bi, n);

        if (pos == -1) {
            cout << 0 << "\n";
        } else {
            int count = n - pos + 1;
            range_update(pos, n, n);
            cout << count << "\n";
        }
    }

    return 0;
}
