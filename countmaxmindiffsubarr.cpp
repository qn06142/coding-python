#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
long long a[MAXN];
long long segMax[4 * MAXN], segMin[4 * MAXN];

void buildMax(int node, int l, int r) {
    if (l == r) {
        segMax[node] = a[l];
    } else {
        int mid = (l + r) / 2;
        buildMax(node * 2, l, mid);
        buildMax(node * 2 + 1, mid + 1, r);
        segMax[node] = max(segMax[node * 2], segMax[node * 2 + 1]);
    }
}

long long getMax(int node, int l, int r, int x, int y) {
    if (x > r || y < l) {
        return LONG_LONG_MIN;
    }
    if (x <= l && y >= r) {
        return segMax[node];
    }
    int mid = (l + r) / 2;
    return max(getMax(node * 2, l, mid, x, y), getMax(node * 2 + 1, mid + 1, r, x, y));
}

void buildMin(int node, int l, int r) {
    if (l == r) {
        segMin[node] = a[l];
    } else {
        int mid = (l + r) / 2;
        buildMin(node * 2, l, mid);
        buildMin(node * 2 + 1, mid + 1, r);
        segMin[node] = min(segMin[node * 2], segMin[node * 2 + 1]);
    }
}

long long getMin(int node, int l, int r, int x, int y) {
    if (x > r || y < l) {
        return LONG_LONG_MAX;
    }
    if (x <= l && y >= r) {
        return segMin[node];
    }
    int mid = (l + r) / 2;
    return min(getMin(node * 2, l, mid, x, y), getMin(node * 2 + 1, mid + 1, r, x, y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    buildMax(1, 0, n - 1);
    buildMin(1, 0, n - 1);

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int l = i, r = n - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (getMax(1, 0, n - 1, i, mid) - getMin(1, 0, n - 1, i, mid) <= k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans += r - i + 1;
    }

    cout << ans << "\n";
    return 0;
}