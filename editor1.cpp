#include <bits/stdc++.h>
using namespace std;
#define int long long
struct op {
    char t;
    int a;
};

int cursor;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &i : a) cin >> i;

    list<int> numbers(a.begin(), a.end());
    auto it = numbers.end();

    vector<op> queries;
    for (int i = 0; i < q; i++) {
        char c;
        cin >> c;
        if (c == 'A') {
            int x;
            cin >> x;
            queries.push_back({c, x});
        } else {
            queries.push_back({c, 0});
        }
    }

    for (const op &cur : queries) {
        if (cur.t == 'A') {

            numbers.insert(it, cur.a);
        } else if (cur.t == 'D') {

            if (it != numbers.begin()) {
                auto to_delete = prev(it);
                numbers.erase(to_delete);
            }
        } else if (cur.t == 'L') {

            if (it != numbers.begin()) {
                it = prev(it);
            }
        } else if (cur.t == 'R') {

            if (it != numbers.end()) {
                it = next(it);
            }
        } else if (cur.t == 'Q') {

            int max_sum = INT_MIN, current_sum = 0;
            for (int x : numbers) {
                current_sum += x;
                max_sum = max(max_sum, current_sum);
            }
            cout << max_sum << '\n';
        }
    }

    return 0;
}
