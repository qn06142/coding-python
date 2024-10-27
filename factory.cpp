#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef DEBUG
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<pair<int, int>> products(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> products[i].first >> products[i].second;
    }
    sort(products.begin() + 1, products.end());
    vector<int> prods(1e5);
    for(int i = 1; i <= n; i++) {
        prods[products[i].first]++;
        prods[products[i].second + products[i].first]--;
    }
    for(int i = 1; i <= 1e5; i++) {
        prods[i] += prods[i - 1];
    }
    cout << *max_element(prods.begin(), prods.end()) << endl;
}
