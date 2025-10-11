#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;
    cin >> N >> k;
    vector<bool> banned(10, false);
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        banned[d] = true;
    }

    vector<bool> visited(N, false);
    vector<int> parent(N, -1);
    vector<int> parent_digit(N, -1);
    queue<int> q;

    for (int d = 1; d <= 9; d++) {
        if (banned[d]) continue;
        int r = d % N;
        if (!visited[r]) {
            visited[r] = true;
            parent[r] = -1;              
            parent_digit[r] = d;
            q.push(r);
        }
    }

    int found_rem = -1;
    while (!q.empty()) {
        int r = q.front(); q.pop();
        if (r == 0) {
            found_rem = r;
            break;
        }

        for (int d = 0; d <= 9; d++) {
            if (banned[d]) continue;
            int nr = (r * 10 + d) % N;
            if (!visited[nr]) {
                visited[nr] = true;
                parent[nr] = r;
                parent_digit[nr] = d;
                q.push(nr);
            }
        }
    }

    if (found_rem == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    string s;
    int cur = 0;
    while (cur != -1) {
        s.push_back(char('0' + parent_digit[cur]));
        cur = parent[cur];
    }
    reverse(s.begin(), s.end());

    if ((int)s.size() < 9) {
        cout << s;
    } else {
        int g = s.size();
        cout << s.substr(0, 3) << "..." << s.substr(g-3, 3) << "(" << g << " digits)";
    }
}