#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int block_sz = 700;         
    const int bits = 16;
    const int M = 1 << bits;          

    int Q;
    if (!(cin >> Q)) return 0;

    static int base[M];
    static int delta[M];
    static int g[M];
    static unsigned char check[M]; 
    vector<int> changed;
    int ops = 0;

    auto rebuild = [&]() {

        for (int m : changed) {
            base[m] += delta[m];
            delta[m] = 0;
            check[m] = 0; 
        }
        changed.clear();

        for (int mask = 0; mask < M; ++mask) g[mask] = base[mask];
        for (int b = 0; b < bits; ++b) {
            for (int mask = 0; mask < M; ++mask) {
                if (mask & (1 << b)) g[mask] += g[mask ^ (1 << b)];
            }
        }
        ops = 0;
    };

    string op;
    int s;
    while (Q--) {
        cin >> op >> s;
        if (op == "add") {

            if (!check[s]) {
                changed.push_back(s);
                check[s] = 1;
            }
            delta[s] += 1;
            ++ops;
        } else if (op == "del") {
            if (!check[s]) {
                changed.push_back(s);
                check[s] = 1;
            }
            delta[s] -= 1;
            ++ops;
        } else if (op == "cnt") {
            long long ans = g[s];

            for (int m : changed) {
                if ((m & s) == m) ans += delta[m]; 
            }
            cout << ans << '\n';
        }
        if (ops >= block_sz) rebuild();
    }
}