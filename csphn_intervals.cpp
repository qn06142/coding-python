#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    
    sort(intervals.begin(), intervals.end());
    
    
    multiset<int> active;
    long long count = 0;

    for (int i = 0; i < n; ++i) {
        int L = intervals[i].first, R = intervals[i].second;

        
        while (!active.empty() && *active.begin() < L) {
            active.erase(active.begin());
        }

        
        count += active.size();
        
        
        active.insert(R);
    }

    cout << count << "\n";
    return 0;
}
