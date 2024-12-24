#include <bits/stdc++.h>

using namespace std;

int main() {
    #define int long long
    int n, q;
    std::cin >> n >> q;

    std::vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> seq[i];
    }

    int cursor = n; // Starting at the end (position n+1)

    for (int operation = 0; operation < q; ++operation) {
        char op;
        std::cin >> op;

        if (op == 'A') {
            int x;
            std::cin >> x;
            seq.insert(seq.begin() + cursor, x);
            cursor++;
        } else if (op == 'D') {
            if (cursor > 1 && cursor <= seq.size()) {
                seq.erase(seq.begin() + cursor-- - 1);
            }
        } else if (op == 'L') {
            if (cursor > 1) {
                cursor--;
            }
        } else if (op == 'R') {
            if (cursor < seq.size()) {
                cursor++;
            }
        } else if (op == 'Q') {
            int l, r;
            std::cin >> l >> r;
	        int sum = 0;
            l = max(1LL, l);
            r = min((long long) seq.size(), r);
            for (int i = l - 1; i <= r - 1; ++i) {
                sum += seq[i];
            }
            std::cout << sum << '\n';
        }

        // for (int i : seq) {
        // 	cout << i << ' ';
        // }
        // cout << '\n';
    }

    return 0;
}
