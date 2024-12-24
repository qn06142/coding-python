#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXV = 2e5 + 5; 

int a[MAXN];
int b[MAXN];
int bit[MAXV];

void update(int x, int v) {
    while (x < MAXV) {
        bit[x] = min(bit[x], v);
        x += x & -x;
    }
}

int get(int x) {
    int ans = INT_MAX;
    while (x > 0) {
        ans = min(ans, bit[x]);
        x -= x & -x;
    }
    return ans;
}

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> cmp;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cmp.push_back(a[i]);
        cmp.push_back(a[i] - p);
    }

    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());

    int shift = 1; 
    for (int i = 1; i <= n; i++) {
        b[i] = lower_bound(cmp.begin(), cmp.end(), a[i] - p) - cmp.begin() + shift;
        a[i] = lower_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin() + shift;
    }

    fill(bit, bit + MAXV, INT_MAX);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int prev_idx = get(b[i]);
        if (prev_idx != INT_MAX) {
            ans = max(ans, i - prev_idx);
        }
        update(a[i], i);
    }

    cout << ans << '\n';
    return 0;
}