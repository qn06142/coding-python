#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;

    cin >> t;
    while(t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n), s(n), c(n), b(n);

        for (int i = 0; i < n; i++)
            cin >> a[i] >> s[i] >> c[i] >> b[i];

        priority_queue<pair<long long,long long>,
            vector<pair<long long,long long>>,
            greater<pair<long long,long long>>> pq;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long d = i + 1;
            long long x = s[i] - d * k;
            long long y = b[i] - d * k;

            if (a[i] > 0)
                pq.push({x, a[i]});

            long long rem = c[i], cnt = 0;

            while (rem && !pq.empty() && pq.top().first < y) {
                pair<long long,long long> cur = pq.top();
                pq.pop();

                long long take = min(rem, cur.second);
                ans += take * (y - cur.first);

                rem -= take;
                cnt += take;
                cur.second -= take;

                if (cur.second)
                    pq.push(cur);
            }

            if (cnt)
                pq.push({y, cnt});
        }

        cout << ans << '\n';
    }
}
