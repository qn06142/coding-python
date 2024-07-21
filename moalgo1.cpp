#include <bits/stdc++.h>
using namespace std;
#define int long long
int count_[(int) 1e6 + 5];
int a[(int) 1e6 + 5];

long long removex(long long curr, long long elem) {
    curr -= count_[elem] * count_[elem] * elem;
    count_[elem]--;
    curr += count_[elem] * count_[elem] * elem;
    return curr;
}

long long addx(long long curr, long long elem) {
    curr -= count_[elem] * count_[elem] * elem;
    count_[elem]++;
    curr += count_[elem] * count_[elem] * elem;
    return curr;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<tuple<int, int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = make_tuple(l, r, i);
    }

    int block_size = sqrt(n);
    sort(queries.begin(), queries.end(), [block_size](tuple<int, int, int> a, tuple<int, int, int> b) {
        int block_a = get<0>(a) / block_size;
        int block_b = get<0>(b) / block_size;
        if (block_a != block_b)
            return block_a < block_b;
        return get<1>(a) < get<1>(b);
    });

    vector<long long> results(q);
    int current_l = 1, current_r = 0;
    long long current_strength = 0;

    for (auto [l, r, idx] : queries) {
        while (current_r < r) {
            current_r++;
            current_strength = addx(current_strength, a[current_r]);
        }
        while (current_r > r) {
            current_strength = removex(current_strength, a[current_r]);
            current_r--;
        }
        while (current_l < l) {
            current_strength = removex(current_strength, a[current_l]);
            current_l++;
        }
        while (current_l > l) {
            current_l--;
            current_strength = addx(current_strength, a[current_l]);
        }
        results[idx] = current_strength;
    }

    for (long long result : results) {
        cout << result << '\n';
    }

    return 0;
}
