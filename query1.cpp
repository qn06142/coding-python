#include<bits/stdc++.h>

using namespace std;
int a[(int) 1e5 + 5], bit[(int) 1e5 + 5];
int update(int x, int y) {
    for(; x <= (int) 1e5 + 5; x += x & (-x)) bit[x] += y;
    return 0;
}
int query(int x) {
    int ret = 0;
    for(; x > 0; x -= x & (-x)) ret += bit[x];
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        char x;
        cin >> x;
        if(x == 'S') {
            int x, y;
            cin >> x >> y;
            update(x, y);
        } else {
            int x, y;
            cin >> x >> y;
            cout << query(y) - query(x - 1) << '\n';
        }
    }
}