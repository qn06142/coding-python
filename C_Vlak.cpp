#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[26];
    bool has_nina = false;
    bool has_emilija = false;
    Node() { fill(begin(next), end(next), -1); }
};

vector<Node> trie;
vector<int> dp_nina, dp_emilija;

void insert_word(const string &s, bool is_nina) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
        if (is_nina) trie[v].has_nina = true;
        else trie[v].has_emilija = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    trie.clear();
    trie.emplace_back(); // root

    string word;
    for (int i = 0; i < n; i++) {
        cin >> word;
        insert_word(word, true);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> word;
        insert_word(word, false);
    }

    int total_nodes = trie.size();
    dp_nina.assign(total_nodes, 0);
    dp_emilija.assign(total_nodes, 0);

    // generate order for postprocessing
    vector<int> order;
    order.reserve(total_nodes);
    stack<int> st;
    st.push(0);
    while (!st.empty()) {
        int v = st.top(); st.pop();
        order.push_back(v);
        for (int c = 0; c < 26; c++) {
            int u = trie[v].next[c];
            if (u != -1) st.push(u);
        }
    }
    reverse(order.begin(), order.end());

    for (int v : order) {
        // nina's turn
        bool can_win_nina = false;
        for (int c = 0; c < 26; c++) {
            int u = trie[v].next[c];
            if (u == -1) continue;
            if (!trie[u].has_nina) continue;
            if (dp_emilija[u] == 0) {
                can_win_nina = true;
                break;
            }
        }
        dp_nina[v] = can_win_nina ? 1 : 0;

        // emilija's turn
        bool can_win_emilija = false;
        for (int c = 0; c < 26; c++) {
            int u = trie[v].next[c];
            if (u == -1) continue;
            if (!trie[u].has_emilija) continue;
            if (dp_nina[u] == 0) {
                can_win_emilija = true;
                break;
            }
        }
        dp_emilija[v] = can_win_emilija ? 1 : 0;
    }

    if (dp_nina[0]) cout << "Nina\n";
    else cout << "Emilija\n";
}
