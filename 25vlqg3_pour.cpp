#include <bits/stdc++.h>
using namespace std;
using State = array<int, 3>;

struct MoveInfo {
    State prev;
    int from;
    int to;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    State init;
    if (!(cin >> init[0] >> init[1] >> init[2])) return 0;

    if (init[0] == 0 || init[1] == 0 || init[2] == 0) {
        cout << 0;
        return 0;
    }

    queue<State> q;
    unordered_map<string, MoveInfo> parent;
    auto encode = [&](const State &s){ return to_string(s[0]) + "," + to_string(s[1]) + "," + to_string(s[2]); };

    string init_key = encode(init);
    parent[init_key] = { {}, -1, -1 };  
    q.push(init);
    State goal;
    bool found = false;

    while (!q.empty() && !found) {
        State cur = q.front(); q.pop();

        for (int i = 0; i < 3 && !found; ++i) {
            for (int j = 0; j < 3 && !found; ++j) {
                if (i == j) continue;
                int vi = cur[i], vj = cur[j];
                if (vj <= 0) continue;       
                if (vi < vj) continue;       
                State nxt = cur;
                nxt[i] = vi - vj;
                nxt[j] = vj * 2;
                string key = encode(nxt);
                if (parent.count(key)) continue;
                parent[key] = { cur, i, j };
                if (nxt[0] == 0 || nxt[1] == 0 || nxt[2] == 0) {
                    goal = nxt;
                    found = true;
                    break;
                }
                q.push(nxt);
            }
        }
    }

    if (!found) {

        cout << "-1";
        return 0;
    }

    vector<pair<int,int>> moves;
    string key = encode(goal);
    while (true) {
        MoveInfo info = parent[key];
        if (info.from == -1) break;  
        moves.emplace_back(info.from + 1, info.to + 1);
        key = encode(info.prev);
    }
    reverse(moves.begin(), moves.end());

    cout << moves.size() << '\n';
    for (auto &mv : moves) {
        cout << mv.first << ' ' << mv.second << '\n';
    }
}