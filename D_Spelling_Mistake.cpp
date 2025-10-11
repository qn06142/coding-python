#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[26];
    bool terminal;
    Node() {
        fill(begin(next), end(next), -1);
        terminal = false;
    }
};

vector<Node> trie;

void insert_word(const string &s) {
    int cur = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[cur].next[c] == -1) {
            trie[cur].next[c] = trie.size();
            trie.emplace_back();
        }
        cur = trie[cur].next[c];
    }
    trie[cur].terminal = true;
}

int best_for_pattern;
string pattern;
int mlen;

void dfs_trie(int node, const vector<int> &prev_row) {

    int min_prev = *min_element(prev_row.begin(), prev_row.end());
    if (min_prev > best_for_pattern) return;

    for (int c = 0; c < 26; ++c) {
        int child = trie[node].next[c];
        if (child == -1) continue;
        vector<int> cur(mlen + 1);
        cur[0] = prev_row[0] + 1;
        char ch = 'a' + c;
        int local_min = cur[0];
        for (int j = 1; j <= mlen; ++j) {
            int cost = (pattern[j-1] == '?' || pattern[j-1] == ch) ? 0 : 1;
            int v1 = prev_row[j] + 1;       
            int v2 = cur[j-1] + 1;         
            int v3 = prev_row[j-1] + cost; 
            cur[j] = min(v1, min(v2, v3));
            if (cur[j] < local_min) local_min = cur[j];
        }

        if (trie[child].terminal) {
            if (cur[mlen] < best_for_pattern) best_for_pattern = cur[mlen];
        }

        if (local_min <= best_for_pattern) {
            dfs_trie(child, cur);
        }
    }
}

int solve_for_pattern(const string &p) {
    pattern = p;
    mlen = pattern.size();

    vector<int> prev(mlen + 1);
    for (int j = 0; j <= mlen; ++j) prev[j] = j; 
    best_for_pattern = INT_MAX / 4;

    if (trie[0].terminal) {
        if (prev[mlen] < best_for_pattern) best_for_pattern = prev[mlen];
    }
    dfs_trie(0, prev);
    return best_for_pattern;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    trie.clear();
    trie.emplace_back(); 
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        insert_word(s);
    }
    int m;
    cin >> m;
    long long total = 0;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        int ans = solve_for_pattern(s);

        total += ans;
    }
    cout << total << "\n";
    return 0;
}