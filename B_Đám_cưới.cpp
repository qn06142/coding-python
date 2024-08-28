#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long pref[(int) 1e6 + 4];
int main() {
    #define int long long
    ios_base::sync_with_stdio(false);
    int T, m;
    cin >> T >> m;
    vector<pair<int, int>> bridges(m);
    for (int i = 0; i < m; i++) {
        cin >> bridges[i].first >> bridges[i].second;
    }

    sort(bridges.begin(), bridges.end());
    for(auto i:bridges) {
        pref[i.first]++;
        pref[i.second]--;
    }
    for(int i = 0; i <= (int) 1e6; i++) {
        pref[i] += pref[i - 1];
    }
    cout << *max_element(pref, pref + (int)1e6 + 1);
    return 0;
}