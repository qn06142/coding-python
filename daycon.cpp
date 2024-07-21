#include<bits/stdc++.h>
#define X first
#define Y second
#define all(x) begin(x), end(x)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, b, a) for(int i = (b); i >= (a); i--)
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define mxx max_element
#define mnn min_element
#define SQR(x) (1LL * (x) * (x))
#define MASK(i) (1LL << (i))
#define Point Vector
#define left Left
#define right Right
#define div Div

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<db, db> pdb;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef pair<ll, int> pli;
typedef pair<ll, pii> plii;

template<class A, class B>
    bool maximize(A& x, B y) {
        if (x < y) return x = y, true; else return false;
    }
template<class A, class B>
    bool minimize(A& x, B y) {
        if (x > y) return x = y, true; else return false;
    }

const int N = 4e5 + 7;

int n, Q, a[N];

struct SegmentTree {
    struct Node {
        int cnt, lazy, left, right;
        Node() : cnt(0), lazy(-1), left(0), right(0) {}
    };

    vector<Node> st;

    SegmentTree(int size) {
        st.resize(4 * size);
    }

    void Up(int id, int l, int r) {
        if (l == r) return;
        st[id].cnt = st[id * 2].cnt + st[id * 2 + 1].cnt + (st[id * 2].right != st[id * 2 + 1].left);
        st[id].left = st[id * 2].left;
        st[id].right = st[id * 2 + 1].right;
    }

    void Down(int id, int l, int r) {
        if (l != r) {
            if (st[id].lazy == -1) return;
            st[id * 2].lazy = st[id].lazy;
            st[id * 2].cnt = 0;
            st[id * 2 + 1].lazy = st[id].lazy;
            st[id * 2 + 1].cnt = 0;
            st[id * 2].left = st[id * 2].right = st[id].lazy;
            st[id * 2 + 1].left = st[id * 2 + 1].right = st[id].lazy;
        }
        st[id].lazy = -1;
    }

    void build(int id, int l, int r) {
        if (l == r) {
            st[id].cnt = 0;
            st[id].left = st[id].right = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        Up(id, l, r);
    }

    void update(int id, int l, int r, int u, int v, int x) {
        Down(id, l, r);
        if (l > v || r < u) return;
        if (u <= l && r <= v) {
            st[id].lazy = x;
            st[id].cnt = 0;
            st[id].left = x;
            st[id].right = x;
            return;
        }
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, u, v, x);
        update(id * 2 + 1, mid + 1, r, u, v, x);
        Up(id, l, r);
    }

    Node get_num(int id, int l, int r, int u, int v) {
        Down(id, l, r);
        if (l > v || r < u) return Node();
        if (u <= l && r <= v) return st[id];
        int mid = (l + r) >> 1;
        Node L = get_num(id * 2, l, mid, u, v);
        Node R = get_num(id * 2 + 1, mid + 1, r, u, v);
        if (L.cnt == -1) return R;
        if (R.cnt == -1) return L;
        Node res;
        res.cnt = L.cnt + R.cnt + (L.right != R.left);
        res.left = L.left;
        res.right = R.right;
        return res;
    }

    int get_num(int L, int R) {
        return get_num(1, 1, n, L, R).cnt;
    }
} st(N);

int main() {
    #ifndef ONLINE_JUDGE
    freopen("DAYCON.INP", "r", stdin);
    freopen("DAYCON.OUT", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    // Coordinate compression
    vector<int> coords(n);
    FOR(i, 1, n) {
        cin >> a[i];
        coords[i - 1] = a[i];
    }

    st.build(1, 1, n);
    cin >> Q;
    while (Q--) {
        int type, L, R, x;
        cin >> type;
        if (type == 1) {
            cin >> L >> R >> x;
            st.update(1, 1, n, L, R, x);
        } else {
            cin >> L >> R;
            cout << st.get_num(L, R) << "\n";
        }
    }
    return 0;
}
