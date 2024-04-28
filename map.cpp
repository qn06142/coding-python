#include<iostream>
#include<map>
#include<climits>
using namespace std;
int a[(int) 1e5 + 5], pref[(int) 1e5 + 5];
map<int, int> dict;
int main() {
    int n;
    cin >> n;
    pref[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = a[i] + pref[i - 1];
    }
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++) {
        if(dict.find(a[i]) != dict.end()){
            ans = max(ans, pref[i] - dict[a[i]]);
            dict[a[i]] = min(dict[a[i]], pref[i - 1]);
        } else {
            dict[a[i]] = pref[i - 1];
        }
    }
    //cout << endl;
    //for(int i = 1; i <= n; i++) cout << dict[a[i]] << endl;
    cout << ans;
}