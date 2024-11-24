#include <bits/stdc++.h>
using namespace std;

struct Event {
    int x, y1, y2;
    bool is_start; 
    Event(int x, int y1, int y2, bool is_start) : x(x), y1(y1), y2(y2), is_start(is_start) {}
};
class BIT {
    int n;
    bool reversed;
    std::vector<int> tree;

public:

    BIT(int size, bool reversedMode = false) : n(size), reversed(reversedMode) {
        tree.resize(n + 1, 0);  
    }

    void update(int idx, int val) {
        if (reversed) idx = n - idx + 1;  
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }

    int sum(int idx) const {
        if (reversed) idx = n - idx + 1;  
        int result = 0;
        while (idx > 0) {
            result += tree[idx];
            idx -= idx & -idx;
        }
        return result;
    }

    int rangeSum(int left, int right) const {
        if (reversed) {
            return sum(left) - sum(right + 1);
        }
        return sum(right) - sum(left - 1);
    }
};
struct rect {
    int x, y, a, b;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<rect> a(n + 1);
        vector<Event> events;
        set<int> y_coords;
        vector<int> cmp;
        for(int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y >> a[i].a >> a[i].b;
            cmp.push_back(a[i].x);
            cmp.push_back(a[i].y);
            cmp.push_back(a[i].a);
            cmp.push_back(a[i].b);
        }
        sort(cmp.begin(), cmp.end());
        cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
        for(int i = 1; i <= n; i++) {
            a[i].x = lower_bound(cmp.begin(), cmp.end(), a[i].x) - cmp.begin() + 1;
            a[i].y = lower_bound(cmp.begin(), cmp.end(), a[i].y) - cmp.begin() + 1;
            a[i].a = lower_bound(cmp.begin(), cmp.end(), a[i].a) - cmp.begin() + 1;
            a[i].b = lower_bound(cmp.begin(), cmp.end(), a[i].b) - cmp.begin() + 1;
            events.emplace_back(a[i].x, a[i].y, a[i].b, true);  
            events.emplace_back(a[i].a, a[i].y, a[i].b, false); 
        }

        sort(events.begin(), events.end(), [](const Event &e1, const Event &e2) {
            if (e1.x == e2.x)
                return e1.is_start > e2.is_start;
            return e1.x < e2.x;
        });

        long long ans = 0;
        int max_ = cmp.size();
        BIT l(max_ + 5, 1), r(max_ + 5, 0);
        int curr = 0;
        for (const auto& event : events) {
            if(event.is_start) {
                ans += curr - r.sum(event.y1 - 1) - l.sum(event.y2 + 1);
                l.update(event.y1, 1);
                r.update(event.y2, 1);
                curr++;
            } else {
                l.update(event.y1, -1);
                r.update(event.y2, -1);
                curr--;
            }
        }

        cout << ans << '\n';
    }
}