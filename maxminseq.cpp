#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 5e5 + 7;

int n, a[N], k;
long long f[N], g[N];

multiset<int> s;

void add(int x) {
    s.insert(x);
}

void del(int x) {
    s.erase(s.find(x));
}

int get_value() {
    auto it = s.end();
    --it;
    return *it - *s.begin();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // Tìm f[i]
    int j = 1;
    add(a[1]);
    for (int i = 1; i <= n; ++i) {
        if (j < i) {
            add(a[i]);
            j = i;
        }
        while (j < n && get_value() < k) {
            ++j;
            add(a[j]);
        }
        f[i] = (j <= n && get_value() == k) ? j : -1;
        del(a[i]);
    }

    // Tìm g[i]
    j = 1;
    s.clear();
    add(a[1]);
    for (int i = 1; i <= n; ++i) {
        if (j < i) {
            add(a[i]);
            j = i;
        }
        while (j < n && get_value() <= k) {
            ++j;
            add(a[j]);
        }
        if (get_value() > k) {
            del(a[j]);
            --j;
            g[i] = (get_value() == k) ? j : -1;
        } else if (j == n) {
            int val = get_value();
            g[i] = (val == k) ? j : ((val < k) ? -1 : g[i]);
        }
        del(a[i]);
    }

    // Tính kết quả
    long long res = 0;
    for (int i = 1; i <= n; ++i)
        if (f[i] != -1 && g[i] != -1) res += g[i] - f[i] + 1;

    cout << res;
    return 0;
}