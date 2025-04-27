#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());  

    vector<int> times(n);
    for(int i = 0; i < n; i++){
        times[i] = a[i].first;
    }

    long long balanced = 0;
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        auto it1 = lower_bound(times.begin(), times.end(), l);
        auto it2 = upper_bound(times.begin(), times.end(), r);
        int cnt = it2 - it1;
        if(k >= 1){

            balanced++;
        } else {

            if(cnt % 2 == 0) 
                balanced++;
        }
    }

    vector<char> s_sorted(n);
    for(int p = 0; p < n; p++){
        s_sorted[p] = (p % 2 == 0 ? 'N' : 'K');
    }

    string s(n, '?');
    for(int p = 0; p < n; p++){
        int orig_idx = a[p].second;
        s[orig_idx] = s_sorted[p];
    }

    cout << balanced << "\n";
    cout << s << "\n";

    return 0;
}