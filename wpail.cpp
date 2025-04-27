#include <iostream>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

struct State {
    int x, y, steps;
};

int main() {
    int x_cap, y_cap, m, k;
    cin >> x_cap >> y_cap >> k >> m;
    
    queue<State> q;
    set<pair<int, int>> visited;
    int best = 0;

    q.push({0, 0, 0});
    visited.insert({0, 0});

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        int total = cur.x + cur.y;
        if (abs(m - total) < abs(m - best)) {
            best = total;
        } else if (abs(m - total) == abs(m - best)) {
            best = max(best, total);  
        }

        if (cur.steps == k) continue;

        State next_states[] = {
            {x_cap, cur.y, cur.steps + 1},       
            {cur.x, y_cap, cur.steps + 1},       
            {0, cur.y, cur.steps + 1},           
            {cur.x, 0, cur.steps + 1},           

            {
                max(0, cur.x - (y_cap - cur.y)),
                min(y_cap, cur.y + cur.x),
                cur.steps + 1
            },

            {
                min(x_cap, cur.x + cur.y),
                max(0, cur.y - (x_cap - cur.x)),
                cur.steps + 1
            }
        };

        for (State next : next_states) {
            if (visited.count({next.x, next.y}) == 0) {
                visited.insert({next.x, next.y});
                q.push(next);
            }
        }
    }

    cout << abs(best - m) << endl;
    return 0;
}
