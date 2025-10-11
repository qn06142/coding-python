#include <bits/stdc++.h>
using namespace std;

string invert_bwt(const string &bwt, char sentinel = 0, int primary_index = -1) {
    int n = (int)bwt.size();
    if (n == 0) return string();

    array<int, 256> cnt{};
    cnt.fill(0);
    for (int i = 0; i < n; ++i) cnt[(unsigned char)bwt[i]]++;

    vector<int> rank(n);
    array<int, 256> occ{};
    occ.fill(0);
    for (int i = 0; i < n; ++i) {
        unsigned char c = (unsigned char)bwt[i];
        rank[i] = occ[c]++;
    }

    array<int, 256> start{};
    start.fill(0);
    int sum = 0;
    for (int ch = 0; ch < 256; ++ch) {
        start[ch] = sum;
        sum += cnt[ch];
    }

    int pos = -1;
    if (sentinel != 0) {

        if (cnt[(unsigned char)sentinel] != 1) {

            if (primary_index >= 0 && primary_index < n) {
                pos = primary_index;
            } else {
                throw runtime_error("Sentinel not unique/absent AND no valid primary_index provided.");
            }
        } else {

            for (int i = 0; i < n; ++i) {
                if (bwt[i] == sentinel) { pos = i; break; }
            }
        }
    } else {
        if (primary_index >= 0 && primary_index < n) pos = primary_index;
        else throw runtime_error("Either provide a unique sentinel or a primary_index.");
    }

    string res(n, '\0');
    int idx = pos;
    for (int k = n - 1; k >= 0; --k) {
        res[k] = bwt[idx];
        unsigned char c = (unsigned char)bwt[idx];
        idx = start[c] + rank[idx];
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string bwt;
    while (getline(cin, bwt)) {

        try {
            string orig = invert_bwt(bwt, '@', -1);
            orig.pop_back();
            cout << orig << "\n";
        } catch (const runtime_error &e) {
            cerr << "ERROR: " << e.what() << "\n";

        }
    }
}