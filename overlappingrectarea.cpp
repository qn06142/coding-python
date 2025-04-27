#include<iostream>
#include<algorithm>
using namespace std;
pair<long long, long long> a[(long long) 1e5 + 5];
int main() {
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++) {
        cin >> a[i].first;
    }
    for(long long i = 1; i <= n; i++) {
        cin >> a[i].second;
    }
    
    sort(a + 1, a + n + 1, greater<pair<long long, long long>>());
    long long ans = 0;
    long long max_ = 0;
    for(long long i = 1; i <= n; i++) {
        if(a[i].second > max_) ans += (a[i].second - max_) * a[i].first;
        max_ = max(max_, a[i].second);
    }
    cout << ans;
}