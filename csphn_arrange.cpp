#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
pair<int, int> a[(int) 1e6 + 6];
int main() {
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    vector<int> ans;
    sort(a + 1, a + 1 + n);
    int currgroup = a[1].first;
    int currmin = a[1].second;
    for(int i = 1; i <= n; i++) { 
        if(currgroup != a[i].first) {
            ans.push_back(currmin);
            currgroup = a[i].first;
            currmin = a[i].second;
            continue;
        }
        currmin = min(a[i].second, currmin);
    }
    ans.push_back(currmin);
    cout << ans.size() << endl;
    for(auto i:ans) cout << i << ' ';
    return 0;
}
