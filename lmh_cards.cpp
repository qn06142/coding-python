
#include <bits/stdc++.h>
using namespace std;

/*
  Greedy per-prefix:
  For each query [L,R], iterate k = L..R:
    prefix_sum += a[k];
    add a[k] into gift multiset (implemented via counts gift_cnt[v]) and gift_sum += a[k];
    cap = prefix_sum / 2;
    while (gift_sum > cap) remove the largest available gift value (decrement its count).
  Answer = total number of gifts kept.
  
  Note: uses a_i <= 100 to implement multiset as counts[1..100].
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int q;
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        long long prefix_sum = 0;
        long long gift_sum = 0;
        int gift_cnt[101] = {0};
        int total_gifts = 0;
        int max_val_ptr = 100; // pointer to find largest gift to remove
        for (int k = L; k <= R; ++k) {
            int v = a[k];
            prefix_sum += v;
            // take it as gift by default
            gift_cnt[v] += 1;
            gift_sum += v;
            total_gifts += 1;
            long long cap = prefix_sum / 2;
            // if gift_sum too large, remove largest gifts until ok
            while (gift_sum > cap) {
                // find largest value with count > 0
                while (max_val_ptr >= 1 && gift_cnt[max_val_ptr] == 0) --max_val_ptr;
                if (max_val_ptr == 0) break; // shouldn't happen since gift_sum > 0 implies someone present
                // remove one of that value
                gift_cnt[max_val_ptr] -= 1;
                gift_sum -= max_val_ptr;
                total_gifts -= 1;
                // don't move max_val_ptr here; next loop will adjust if needed
            }
        }
        cout << total_gifts << '\n';
    }
    return 0;
}