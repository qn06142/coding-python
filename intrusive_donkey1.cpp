#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, q;
    cin >> n >> q;

    string phrase;
    cin >> phrase;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            long long l, r;
            cin >> l >> r;

            const size_t left = static_cast<size_t>(l - 1);
            const size_t right = static_cast<size_t>(r);

            string updated;
            updated.reserve(phrase.size() + (right - left));
            updated.append(phrase, 0, left);

            for (size_t i = left; i < right; ++i) {
                updated.push_back(phrase[i]);
                updated.push_back(phrase[i]);
            }

            updated.append(phrase, right, string::npos);
            phrase.swap(updated);
        } else if (type == 2) {
            long long i;
            cin >> i;
            cout << phrase[static_cast<size_t>(i - 1)] << '\n';
        }
    }

    return 0;
}
