#include <bits/stdc++.h>
using namespace std;

const int maxn = (int) 5e5 + 3;

struct Node {
    int t, x, y, id;
    long long w;
    bool operator < (const Node &o) const {
        if(t != o.t) return t < o.t;
        if(x != o.x) return x < o.x;
        return y < o.y;
    }
};

int n, sz;
vector<Node> qry;
long long ans[maxn];

struct fenwickTree {
    vector<long long> bit;
    void init(int n) { bit.assign(n + 1, 0); }

    void update(int x, long long w) {
        while(x <= sz) {
            bit[x] += w;
            x += (x & -x);
        }
    }

    long long get(int x) {
        long long s = 0;
        while(x > 0) {
            s += bit[x];
            x -= (x & -x);
        }
        return s;
    }
} BIT;

void cal(int l, int r) {
    if(l + 1 == r) return;
    int mid = (l + r) >> 1;
    cal(l, mid); cal(mid, r);

    int a = l, b = mid;
    vector<pair<int,long long>> rollback;
    vector<Node> temp;

    while(a < mid && b < r) {
        if(qry[a].x <= qry[b].x) {
            if(qry[a].id == -1) {
                BIT.update(qry[a].y, qry[a].w);
                rollback.push_back({qry[a].y, qry[a].w});
            }
            temp.push_back(qry[a++]);
        }
        else {
            if(qry[b].id > 0) {
                ans[qry[b].id] += qry[b].w * BIT.get(qry[b].y);
            }
            temp.push_back(qry[b++]);
        }
    }
    while(b < r) {
        if(qry[b].id > 0) {
            ans[qry[b].id] += qry[b].w * BIT.get(qry[b].y);
        }
        temp.push_back(qry[b++]);
    }
    while(a < mid) temp.push_back(qry[a++]);

    for(int i = l; i < r; i++) qry[i] = temp[i - l];
    for(auto [y, w] : rollback) BIT.update(y, -w);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q, t = 0;
    vector<int> cpr;
    while(cin >> q) {
        if(q == 0) {
            int w; cin >> w;
        }
        else if(q == 1) {
            int x, y, a; cin >> x >> y >> a;
            qry.push_back({t++, x, y, -1, (long long) a});
            cpr.push_back(y);
        }
        else if(q == 2) {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);
            int id = ++n;
            qry.push_back({t, x2,   y2,   id, +1});
            qry.push_back({t, x1-1, y2,   id, -1});
            qry.push_back({t, x2,   y1-1, id, -1});
            qry.push_back({t, x1-1, y1-1, id, +1});
            cpr.push_back(y1 - 1); cpr.push_back(y2);
            t++;
        }
        else if(q == 3) break;
    }

    sort(cpr.begin(), cpr.end());
    cpr.resize(unique(cpr.begin(), cpr.end()) - cpr.begin());
    for(auto &q : qry) {
        q.y = lower_bound(cpr.begin(), cpr.end(), q.y) - cpr.begin() + 1;
    }
    sz = (int) cpr.size() + 2;
    BIT.init(sz);

    sort(qry.begin(), qry.end());
    cal(0, (int) qry.size());

    for(int i = 1; i <= n; i++) cout << ans[i] << "\n";
    return 0;
}
