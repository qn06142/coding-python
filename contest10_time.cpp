#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        long long k;
        cin >> s >> k;
        int n = s.size();

        vector<int> prev(n), next(n);
        vector<bool> alive(n, true);
        vector<int> time_del(n, 0);

        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            next[i] = (i + 1 < n ? i + 1 : -1);
        }
        int head = 0, tail = n - 1;

        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] > s[i + 1]) {
                heap.push(i);
            }
        }

        for (int tstep = 1; tstep <= n; tstep++) {
            int i = -1;

            while (!heap.empty()) {
                int cand = heap.top();
                heap.pop();
                if (!alive[cand]) continue;
                int nxt = next[cand];
                if (nxt != -1 && alive[nxt] && s[cand] > s[nxt]) {
                    i = cand;
                    break;
                }
            }

            if (i == -1) {
                i = tail;
            }

            time_del[i] = tstep;
            alive[i] = false;

            int u = prev[i], v = next[i];
            if (u != -1) next[u] = v;
            else head = v;
            if (v != -1) prev[v] = u;
            else tail = u;

            if (u != -1 && v != -1 && alive[u] && alive[v] && s[u] > s[v]) {
                heap.push(u);
            }
        }

        auto prefix = [&](int p)-> long long {
            return (long long)p * (2LL*n - p + 1) / 2;
        };

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (prefix(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        int p = lo;
        long long Pprev = prefix(p - 1);
        long long d = p - 1;
        long long offset = k - Pprev; 

        char ans = '?';
        for (int i = 0; i < n; i++) {
            if (time_del[i] > d) {
                offset--;
                if (offset == 0) {
                    ans = s[i];
                    break;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}