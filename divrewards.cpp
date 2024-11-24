#include<bits/stdc++.h>

using namespace std;
int n;
const int maxn = 200;
int a[maxn];
pair<long long, long long> stor[1000005];
long long cnt = 0, ans = LONG_LONG_MAX;
void yas(int ind, int end_, long long x = 0, long long y = 0, long long sum = 0) {
    if(ind == end_) {
        if(end_ != n + 1) {
            stor[++cnt] = make_pair(x - y, sum - x - y);
        } else {
            int tmp = lower_bound(stor + 1, stor + 1 + cnt, make_pair(y - x, LONG_LONG_MIN)) - stor;
            if(tmp == cnt + 1 or stor[tmp].first != y - x) return;
            ans = min(ans, stor[tmp].second + sum - x - y);
        }
        return;
    }
    yas(ind + 1, end_, x + a[ind], y, sum + a[ind]);
    yas(ind + 1, end_, x, y + a[ind], sum + a[ind]);
    yas(ind + 1, end_, x, y, sum + a[ind]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n){

        cnt = 0;
        ans = LONG_LONG_MAX;
        for(int i = 0; i <= 1000005; i++) {
            stor[i] = make_pair(0, 0);
        }
        for(int i = 1; i <= n ; i++) cin >> a[i];
        if(n == 1) {
            cout << a[1] <<"\n";
            continue;
        }
        int mid = (n + 1) / 2;
        yas(1, mid + 1);
        sort(stor + 1, stor + 1 + cnt);
        yas(mid + 1, n + 1);
        cout << ans << "\n";
    }
}