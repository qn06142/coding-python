#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<pair<int,int>> compress(const vector<int>& arr) {
    vector<pair<int,int>> comp;
    int n = arr.size();
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1])
            cnt++;
        else {
            comp.push_back({arr[i-1], cnt});
            cnt = 1;
        }
    }
    comp.push_back({arr[n-1], cnt});
    return comp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<pair<int,int>> comp = compress(a);
    int m = comp.size();

    ll internal = 0;
    for(auto &p : comp){
        int freq = p.second;
        internal += (ll)freq * (freq - 1) / 2;
    }

    ll cross = 0;
    int i = 0;
    while(i < m - 1) { 

        int sign = (comp[i+1].first > comp[i].first) ? 1 : -1;
        int j = i;

        while(j + 1 < m) {
            int currSign = (comp[j+1].first > comp[j].first) ? 1 : -1;
            if(currSign != sign) break;
            j++;
        }

        ll S = 0, sq = 0;
        for (int k = i; k <= j; k++){
            S += comp[k].second;
            sq += (ll)comp[k].second * comp[k].second;
        }

        ll segPairs = (S * S - sq) / 2;
        cross += segPairs;

        i = j;
    }

    ll ans = internal + cross;
    cout << ans << "\n";
    return 0;
}