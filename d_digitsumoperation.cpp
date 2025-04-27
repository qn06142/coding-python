#include <bits/stdc++.h>
using namespace std;

long long sum_of_digits(long long x) {
    long long s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    set<int> index_set;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 9)
            index_set.insert(i);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;

            auto it = index_set.lower_bound(l);
            while (it != index_set.end() && *it <= r) {
                int idx = *it;

                ++it;
                a[idx] = sum_of_digits(a[idx]);
                if (a[idx] <= 9) {

                    index_set.erase(idx);
                }

            }
        } else { 
            int x;
            cin >> x;
            cout << a[x] << "\n";
        }
    }

    return 0;
}