#include <bits/stdc++.h>
using namespace std;

static constexpr int MOD = 1000000007;

struct Node {
    array<Node*, 26> nxt;
    int cnt;
    Node() : nxt{}, cnt(0) {
        nxt.fill(nullptr);
    }
    ~Node() {
        for (auto p : nxt)
            delete p;
    }
};

void add(Node* root, const string &s) {
    Node* cur = root;
    cur->cnt++;
    for (char ch : s) {
        int idx = ch - 'a';
        if (0 <= idx && idx < 26) {
            if (!cur->nxt[idx]) {
                cur->nxt[idx] = new Node();
                cur->nxt[idx]->cnt = 0;
            }
            cur = cur->nxt[idx];
            cur->cnt++;
        }
    }
}

bool search(Node* root, const string &s) {
    Node* cur = root;
    for (char ch : s) {
        int idx = ch - 'a';
        if (idx < 0 || idx >= 26 || !cur->nxt[idx])
            return false;
        cur = cur->nxt[idx];
    }
    return cur->cnt > 0;
}

int countpref(Node* root, const string &pref) {
    Node* cur = root;
    for (char ch : pref) {
        int idx = ch - 'a';
        if (idx < 0 || idx >= 26 || !cur->nxt[idx])
            return 0;
        cur = cur->nxt[idx];
    }
    return cur->cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int q;
    cin >> s;
    cin >> q;

    Node* root = new Node();
    for (int i = 0; i < q; i++) {
        string w;
        cin >> w;
        add(root, w);
    }

    int n = s.size();
    vector<int> dp(n+1);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        if (dp[i] == 0) continue;
        long long ways = dp[i];
        Node* cur = root;
        for (int j = i; j < n; j++) {
            int idx = s[j] - 'a';
            if (idx < 0 || idx >= 26 || !cur->nxt[idx]) break;
            cur = cur->nxt[idx];
            if (cur->cnt > 0) {
                dp[j+1] = (dp[j+1] + ways) % MOD;
            }
        }
    }
    cout << dp[n];
}