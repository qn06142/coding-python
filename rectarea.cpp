#include<iostream>
#include<algorithm>
using namespace std;
pair<long long, pair<long long, long long>> a[(long long) 1e5 + 5];
bool cmp(pair<long long, pair<long long, long long>> &a, pair<long long, pair<long long, long long>> &b) {
    return a.second > b.second;
}
int main() {
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second.first >> a[i].second.second;
    }
    sort(a + 1, a + n + 1, cmp);
    long long ans = 0;
    long long max_ = 0;
    for(long long i = 1; i <= n; i++) {
        if(a[i].second.first > max_) ans += (a[i].second.first - max_) * (a[i].second.first - a[i].first);
        max_ = max(max_, a[i].second.first);
        cerr << max_ << endl;
    }
    cout << ans;
}