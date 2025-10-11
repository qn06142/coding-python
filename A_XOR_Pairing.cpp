#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Giới hạn theo bài
const int MAXN = 500000;
const int MAXNODE = MAXN * 31;  // mỗi phần tử nhiều nhất 31 node
const int BITS = 30;

struct Node {
    int ch[2];
    int cnt;
} trie[MAXNODE];
int nodes;         // số node đã cấp
int root[MAXN+1]; // root[i] là trie sau khi thêm A[1..i]

// tạo node mới (hoặc clone từ node cũ nếu cần persistency)
int new_node(int from = 0) {
    int id = ++nodes;
    if (from) trie[id] = trie[from];
    else {
        trie[id].ch[0] = trie[id].ch[1] = 0;
        trie[id].cnt = 0;
    }
    return id;
}

// chèn x vào trie (persistent): trả về id của root mới
int insert_root(int prev_root, int x) {
    int cur = new_node(prev_root);
    int r = cur;
    trie[cur].cnt++;
    for (int b = BITS-1; b >= 0; --b) {
        int bit = (x >> b) & 1;
        int next = new_node(trie[cur].ch[bit]);
        trie[cur].ch[bit] = next;
        cur = next;
        trie[cur].cnt++;
    }
    return r;
}

// Đếm số u trong trie rooted tại rt sao cho
//     u <= (u xor v) <= v
ll query_sub(int rt, int v, int b, bool tight_u, bool tight_v) {
    if (!rt) return 0;
    // nếu đã xuống dưới cùng bit => mọi u ở đây đều hợp lệ
    if (b < 0) {
        return trie[rt].cnt;
    }
    // prune: nếu đã chắc u_prefix < w_prefix (tight_u=false)
//  và w_prefix < v_prefix (tight_v=false), thì cả subtree đều ok
    if (!tight_u && !tight_v) {
        return trie[rt].cnt;
    }
    ll res = 0;
    int vb = (v >> b) & 1;
    // thử mỗi hướng bit của u
    for (int ub = 0; ub < 2; ++ub) {
        int wbit = ub ^ vb;
        int nxt = trie[rt].ch[ub];
        if (!nxt) continue;
        // nếu tight_u: ta cần ubit <= wbit
        if (tight_u && ub > wbit) continue;
        // nếu tight_v: ta cần wbit <= vb
        if (tight_v && wbit > vb) continue;
        // tính tight mới
        bool ntu = tight_u && (ub == wbit);
        bool ntv = tight_v && (wbit == vb);
        res += query_sub(nxt, v, b - 1, ntu, ntv);
    }
    return res;
}

inline ll query(int rt, int v) {
    // ban đầu cả hai chiều đều tight (chưa xác định strict)
    return query_sub(rt, v, BITS-1, true, true);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, Q;
        cin >> N >> Q;
        vector<int> A(N+1);
        for (int i = 1; i <= N; ++i) {
            cin >> A[i];
        }
        // build persistent trie
        nodes = 0;
        trie[0].ch[0] = trie[0].ch[1] = trie[0].cnt = 0;
        root[0] = new_node(0);
        for (int i = 1; i <= N; ++i) {
            root[i] = insert_root(root[i-1], A[i]);
        }

        while (Q--) {
            int L, R;
            cin >> L >> R;
            ll ans = 0;
            for (int y = L; y <= R; ++y) {
                // đếm x in [L,R] là difference của hai prefix tries
                ans += query(root[R], A[y]);
                ans -= query(root[L-1], A[y]);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
