#include<bits/stdc++.h>
using namespace std;

#define debug(...)
#define debugArr(...)
int mat[(int) 4e3 + 5][(int) 4e3 + 5];
int r[(int) 4e1 + 5], c[(int) 4e1 + 5];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            if(x == '+') {
                mat[i][j] = 1;
            } else {
                mat[i][j] = -1;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(mat[i][j] == -1) {
                r[i]++;
                c[j]++;
            }
        }
    }
    debug(r);
    debug(c);
    priority_queue<pair<int, int>> pq;
    for(int i = 1; i <= n; i++) {
        pq.push({c[i], i});
    }
    vector<vector<bool>> ans(n + 1, vector<bool>(n + 1));
    for(int i = 1; i <= n; i++) {
        list<pair<int, int>> tmp;
        for(int i_ = 1; i_ <= r[i]; i_++) {
            if(pq.top().first == 0) {
                pq.pop();
                continue;
            }
            debug(pq.top());
            ans[i][pq.top().second] = 1;
            tmp.push_back({pq.top().first - 1, pq.top().second});
            pq.pop();
        }
        for(pair<int, int> i : tmp) {
            pq.push(i);
        }
        debug(pq);
    }
    debug(r);
    debug(c);
    if(pq.empty()) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}