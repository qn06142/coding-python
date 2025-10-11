#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INFLL = (ll)9e18;

struct LiChao {
    struct Line { ll m, b; 
        Line(ll _m=0, ll _b=-INFLL): m(_m), b(_b) {}
        ll eval(ll x) const { return m * x + b; }
    };
    struct Node {
        Line line;
        Node *l = nullptr, *r = nullptr;
        Node(Line ln): line(ln) {}
    };
    Node* root = nullptr;
    ll L, R;
    LiChao(ll l, ll r): L(l), R(r) {}

    void add_line(Line nw) { root = add_line(root, L, R, nw); }

    Node* add_line(Node* node, ll l, ll r, Line nw) {
        if (!node) return new Node(nw);
        ll mid = (l + r) >> 1;

        if (node->line.eval(mid) < nw.eval(mid)) {

            swap(node->line, nw);
        }
        if (l == r) return node;
        if (node->line.eval(l) < nw.eval(l)) {
            node->l = add_line(node->l, l, mid, nw);
        } else if (node->line.eval(r) < nw.eval(r)) {
            node->r = add_line(node->r, mid+1, r, nw);
        }
        return node;
    }

    ll query(ll x) const { return query(root, L, R, x); }

    ll query(Node* node, ll l, ll r, ll x) const {
        if (!node) return -INFLL;
        ll res = node->line.eval(x);
        if (l == r) return res;
        ll mid = (l + r) >> 1;
        if (x <= mid) {
            return max(res, query(node->l, l, mid, x));
        } else {
            return max(res, query(node->r, mid+1, r, x));
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    long long C;
    long long D;
    cin >> N >> C >> D;
    struct Machine { ll d, p, r, g; };
    vector<Machine> a(N);
    vector<ll> days;
    days.push_back(1); 
    for (int i = 0; i < N; ++i) {
        cin >> a[i].d >> a[i].p >> a[i].r >> a[i].g;
        days.push_back(a[i].d);
    }
    days.push_back(D + 1); 
    sort(days.begin(), days.end());
    days.erase(unique(days.begin(), days.end()), days.end());

    unordered_map<ll, vector<int>> byday;
    byday.reserve(N * 2);
    for (int i = 0; i < N; ++i) byday[a[i].d].push_back(i);

    int M = days.size();
    unordered_map<ll,int> day_index;
    for (int i = 0; i < M; ++i) day_index[days[i]] = i;

    vector<ll> dp(M, -INFLL);

    int idx1 = day_index[1];
    dp[idx1] = C;

    LiChao lichao(0, D);

    for (int i = idx1; i < M; ++i) {
        ll day = days[i];
        if (i > 0) {

            dp[i] = max(dp[i], dp[i-1]);
        }

        ll x = day - 1;
        if (x >= 0) {
            ll q = lichao.query(x);
            dp[i] = max(dp[i], q);
        }

        auto it = byday.find(day);
        if (it != byday.end()) {
            for (int id : it->second) {
                ll p = a[id].p, r = a[id].r, g = a[id].g, d = a[id].d;
                if (dp[i] >= p) {

                    ll intercept = dp[i] - p + r - g * d;

                    lichao.add_line({g, intercept});
                }
            }
        }
    }

    int idx_end = day_index[D+1];
    ll ans = dp[idx_end];
    if (ans < 0) ans = 0; 
    cout << ans;
}
