#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_set<string> dict;
    dict.reserve(n * 2);
    string w;
    int maxlen = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w;
        dict.insert(w);
        maxlen = max(maxlen, (int)w.size());
    }

    int q; cin >> q;
    string s;
    while (q--) {
        cin >> s;
        int L = (int)s.size();
        vector<char> dp(L + 1, 0);
        vector<int> pre(L + 1, -1);
        dp[0] = 1;

        for (int i = 0; i < L; ++i) {
            if (!dp[i]) continue;
            int upto = min(maxlen, L - i);
            for (int len = 1; len <= upto; ++len) {
                int p = i + len;
                if (dp[p]) continue; 
                if (dict.find(s.substr(i, len)) != dict.end()) {
                    dp[p] = 1;
                    pre[p] = i;
                    if (p == L) break; 
                }
            }
        }

        if (!dp[L]) {
            cout << "-1\n";
        } else {
            vector<string> parts;
            int cur = L;
            while (cur > 0) {
                int prev = pre[cur];
                parts.push_back(s.substr(prev, cur - prev));
                cur = prev;
            }
            reverse(parts.begin(), parts.end());
            for (size_t i = 0; i < parts.size(); ++i) {
                if (i) cout << ' ';
                cout << parts[i];
            }
            cout << '\n';
        }
    }
}