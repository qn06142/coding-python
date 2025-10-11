#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[26];
    int cnt;
    int depth;
    Node(int d=0) : cnt(0), depth(d) {
        for (int i=0;i<26;++i) next[i] = -1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if(!(cin >> q)) return 0;

    vector<Node> trie;
    trie.emplace_back(0); 

    vector< multiset<int> > dep;
    auto ensure_depth = [&](int d){
        if ((int)dep.size() <= d) dep.resize(d+1);
    };

    ensure_depth(0);
    dep[0].insert(0);

    vector<vector<int>> apath(q+1);
    vector<char> active(q+1, 0);

    for (int op_idx = 1; op_idx <= q; ++op_idx) {
        int t;
        cin >> t;
        if (t == 1) {
            string s;
            cin >> s;

            reverse(s.begin(), s.end());
            int cur = 0;
            vector<int> path;
            for (int i = 0; i < (int)s.size(); ++i) {
                int c = s[i]-'a';
                if (trie[cur].next[c] == -1) {
                    int new_depth = trie[cur].depth + 1;
                    trie[cur].next[c] = (int)trie.size();
                    trie.emplace_back(new_depth);

                    ensure_depth(new_depth);
                    dep[new_depth].insert(0);
                }
                cur = trie[cur].next[c];
                path.push_back(cur);

                int d = trie[cur].depth;
                int oldcnt = trie[cur].cnt;
                auto it = dep[d].find(oldcnt);

                if (it != dep[d].end()) dep[d].erase(it);
                trie[cur].cnt = oldcnt + 1;
                dep[d].insert(trie[cur].cnt);
            }

            apath[op_idx] = std::move(path);
            active[op_idx] = 1;
        }
        else if (t == 2) {
            int k,l;
            cin >> k >> l;
            if (l >= (int)dep.size() || dep[l].empty()) {
                cout << "NO\n";
            } else {

                int mx = *dep[l].rbegin();
                cout << (mx >= k ? "YES" : "NO") << '\n';
            }
        }
        else if (t == 3) {
            int x; cin >> x;

            if (x >= 1 && x <= q && active[x]) {
                auto &path = apath[x];
                for (int node : path) {
                    int d = trie[node].depth;
                    int oldcnt = trie[node].cnt;
                    auto it = dep[d].find(oldcnt);
                    if (it != dep[d].end()) dep[d].erase(it);
                    trie[node].cnt = oldcnt - 1;
                    dep[d].insert(trie[node].cnt);
                }
                active[x] = 0;
            }

        }
    }

    return 0;
}