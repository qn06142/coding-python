#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    unsigned int c;
    cin >> n >> c;

    vector<pair<int, unsigned int>> ops(n);
    for (int i = 0; i < n; ++i) {
        cin >> ops[i].first >> ops[i].second;
    }

    vector<unsigned int> result(n, 0);

    for (int t = 0; t < 30; ++t) { // since Ai and c are less than 2^30
        vector<int> f(2);
        f[0] = 0; // initial value if bit is 0
        f[1] = 1; // initial value if bit is 1
        bool val = (c & (1 << t)) ? 1 : 0;

        for (int i = 0; i < n; ++i) {
            int Ti = ops[i].first;
            unsigned int Ai = ops[i].second;
            bool bitx = (Ai & (1 << t)) ? 1 : 0;
            vector<int> tmp(2);

            if (Ti == 1) {
                tmp[0] = f[0] & bitx;
                tmp[1] = f[1] & bitx;
            } else if (Ti == 2) {
                tmp[0] = f[0] | bitx;
                tmp[1] = f[1] | bitx;
            } else if (Ti == 3) {
                tmp[0] = f[0] ^ bitx;
                tmp[1] = f[1] ^ bitx;
            }

            f[0] = tmp[0];
            f[1] = tmp[1];
            result[i] |= (f[val] << t);

            val = f[val];
        }
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }

    return 0;
}