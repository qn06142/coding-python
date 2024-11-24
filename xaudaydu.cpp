#include <iostream>
#include <vector>
#include <string>

using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("bmi,avx,avx2")
int main() {
    int n;
    cin >> n;

    vector<int> masks(n);
    const int FULL_ALPHABET_MASK = (1 << 26) - 1;  

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int mask = 0;
        for (char c : s) {
            mask |= (1 << (c - 'a'));
        }
        masks[i] = mask;
    }

    int ans = 0;

    for (int subset = 1; subset < (1 << n); ++subset) {
        int newmask = 0;
        for (int i = 0; i < n; ++i) {
            if (subset & (1 << i)) {
                newmask |= masks[i];
            }
        }

        if (newmask == FULL_ALPHABET_MASK) {
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}
