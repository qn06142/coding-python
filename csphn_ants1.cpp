#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

struct Interval {
    ll L, R;
};

bool is_feasible(ll T, const vector<pair<int,int>> &piles, int k) {
    int n = piles.size();
    vector<Interval> intervals;
    intervals.reserve(n);

    for (int i = 0; i < n; i++) {
        int x = piles[i].first;
        int a = piles[i].second;

        ll D = T / (2LL * a);  
        ll L = x - D;
        ll R = x + D;
        intervals.push_back({L, R});
    }

    sort(intervals.begin(), intervals.end(), [](const Interval &i1, const Interval &i2){
        return i1.R < i2.R;
    });

    int used = 0;
    ll currentDepot = -LLONG_MAX; 

    for(auto &intv : intervals) {
        if(currentDepot < intv.L) {
            used++;
            currentDepot = intv.R; 
            if(used > k)
                return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> positions(n), amounts(n);
    for (int i = 0; i < n; i++){
        cin >> positions[i];
    }
    for (int i = 0; i < n; i++){
        cin >> amounts[i];
    }

    vector<pair<int,int>> piles(n);
    for (int i = 0; i < n; i++){
        piles[i] = {positions[i], amounts[i]};
    }

    if(k >= n){
        cout << 0 << "\n";
        return 0;
    }

    int minX = *min_element(positions.begin(), positions.end());
    int maxX = *max_element(positions.begin(), positions.end());
    int maxA = *max_element(amounts.begin(), amounts.end());
    ll l = 0;
    ll r = 2LL * maxA * (maxX - minX);

    while(l < r){
        ll mid = (l + r) / 2;
        if(is_feasible(mid, piles, k))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << "\n";

    return 0;
}