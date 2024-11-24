#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class BIT {
    vector<int> tree;
    int size;
public:
    BIT(int n) : size(n) {
        tree.resize(n + 1, 0);
    }

    void update(int index, int value) {
        for (; index <= size; index += index & -index) {
            tree[index] = max(tree[index], value);
        }
    }

    int query(int index) {
        int maxVal = 0;
        for (; index > 0; index -= index & -index) {
            maxVal = max(maxVal, tree[index]);
        }
        return maxVal;
    }
};

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> lis(n, 1), lis1(n, 1);
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    gp_hash_table<int, int> compress;
    for (int i = 0; i < n; i++) {
        compress[a[i]] = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin() + 1;
    }

    BIT bit(n);
    for (int i = 0; i < n; i++) {
        int comp_idx = compress[a[i]];
        lis[i] = bit.query(comp_idx - 1) + 1;
        bit.update(comp_idx, lis[i]);
    }

    BIT bit1(n);
    for (int i = n - 1; i >= 0; i--) {
        int comp_idx = compress[a[i]];
        lis1[i] = bit1.query(n - comp_idx) + 1;
        bit1.update(n - comp_idx + 1, lis1[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << lis[i] + lis1[i] - 1 << ' ';
    }
    return 0;
}