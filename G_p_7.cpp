#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
vector<long long> diff, stor;
vector<pair<pair<int, int>, int>> querystor;
vector<pair<int, int>> queries;
vector<int> pref;
void upd(int l, int r, int v) {
    int start = lower_bound(stor.begin(), stor.end(), l) - stor.begin();
    int end = lower_bound(stor.begin(), stor.end(), r) - stor.begin();
    diff[start] += v;
    if (end + 1 < diff.size()) {
        diff[end + 1] -= v;
    }
    // << start << ' ' << end << ' ' << l << ' ' << r << ' ' << v << endl;
}

long long query(int l, int r) {
    long long ans = 0;
    int start = lower_bound(stor.begin(), stor.end(), l) - stor.begin();
    int end = lower_bound(stor.begin(), stor.end(), r) - stor.begin();
    // << start << ' ' << end << ' ' << pref[end - 1] << ' ' << pref[start - 1] << ' ' << diff[end] << endl;
    return (end == 0 ? 0 : pref[end - 1]) - (start == 0 ? 0 : pref[start -1]) + diff[end];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        r--;
        querystor.push_back({{l, r}, v});
        stor.push_back(l);
        stor.push_back(r);
        stor.push_back(r + 1);
    }
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        r--;
        queries.emplace_back(l, r);
        stor.push_back(l);
        stor.push_back(r);
    }

    sort(stor.begin(), stor.end());
    stor.erase(unique(stor.begin(), stor.end()), stor.end());
    diff.resize(stor.size());
    for (auto i : querystor) {
        upd(i.first.first, i.first.second, i.second);
    }
    for(int i = 1; i < diff.size(); i++) {
        diff[i] += diff[i - 1];
    }
    // << endl;
    pref.resize(diff.size());
    pref[0] = diff[0] * (stor[1] - stor[0]);
    for(int i = 1;  i < pref.size() - 1; i++) {
        pref[i] = pref[i - 1] + (stor[i + 1] - stor[i]) * diff[i];
    }
    for (auto i : queries) {
        cout << query(i.first, i.second) << '\n';
    }
    // << endl;
    for(auto i:stor) {
        // << i << ' ';
    }
    // << endl;
    for(auto i:diff) {
        // << i << ' ';
    }
    // << endl;
    for(auto i:pref) {
        // << i << ' ';
    }
    return 0;
}