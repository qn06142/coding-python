#include <bits/stdc++.h>
using namespace std;

const long long MAX_A = 1e5 + 5;
const long long MAX_B = 1e6 + 5;
long long a[MAX_A];
pair<long long, long long> b[MAX_B];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    cin >> n >> m;
    for(long long i=1; i<=n; i++)
        cin >> a[i];
    for(long long i=1; i<=m; i++) {
        cin >> b[i].second;
        b[i].first = i;
    }
    sort(a+1, a+n+1);
    vector<long long> compress(a, a+n);
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    sort(b+1, b+m+1);
    long long j = 0;
    vector<pair<long long, long long>> ans;
    for(long long i = 1; i <= m; i++) {
        while(j + 1 <= (long long) compress.size() && compress[j + 1] < b[i].second) j++;
        ans.push_back(make_pair(b[i].first, b[i].second - j  - 1));
    }
    sort(ans.begin(), ans.end());
    for(auto i : ans)
        cout << i.second << "\n";
    return 0;
}