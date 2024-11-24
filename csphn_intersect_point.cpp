#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Event {
    int x, y1, y2, type;
    Event(int x, int y1, int y2, int type) : x(x), y1(y1), y2(y2), type(type) {}
    bool operator<(const Event &other) const {
        if (x == other.x) return type < other.type;
        return x < other.x;
    }
};

class FenwickTree {
public:
    vector<int> bit;
    int n;
    FenwickTree(int n) : n(n) { bit.assign(n + 1, 0); }

    void update(int idx, int delta) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    int n;
    cin >> n;

    vector<Event> events;
    int MAX_Y = 1e6 + 10; 

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 == y2) { 
            if (x1 > x2) swap(x1, x2);
            events.emplace_back(x1, y1, y1, 1); 
            events.emplace_back(x2, y1, y1, -1); 
        } else { 
            if (y1 > y2) swap(y1, y2);
            events.emplace_back(x1, y1, y2, 0); 
        }
    }

    sort(events.begin(), events.end());
    const int DELTA = 2e6;
    FenwickTree fenwick(MAX_Y + DELTA + 5);
    long long intersections = 0;

    for (const auto &event : events) {
        int x = event.x, y1 = event.y1, y2 = event.y2, type = event.type;
        if (type == 1) { 
            fenwick.update(y1 + DELTA, 1);
        } else if (type == -1) { 
            fenwick.update(y1 + DELTA, -1);
        } else { 
            intersections += fenwick.rangeQuery(y1 + DELTA, y2 + DELTA);
        }
    }

    cout << intersections << endl;

    return 0;
}
