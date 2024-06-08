#include<bits/stdc++.h>
using namespace std;

void process_queries() {
    long long q;
    cin >> q;
    multiset<pair<long long, long long>> S;
    long long cur = 0, cnt = 0;
    while(q-- > 0) {
        long long type, x;
        cin >> type >> x;
        if(type == 1) S.insert({x - cur, ++cnt});
        else if(type == 2) cur += x;
        else {
            while(true)
            {
                auto it = S.lower_bound({x - cur, 0});
                if(it == S.end() || it->first > x - cur) break;
                S.erase(it);
            }
        }
    }
    vector<pair<long long, long long>> vc;
    for(auto i:S) {
        vc.push_back(make_pair(i.second, i.first));
    }
    sort(vc.begin(), vc.end());
    //cout << vc.size() << '\n';
    for(auto v : vc) cout << v.second + cur << " ";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    process_queries();
    return 0;
}
