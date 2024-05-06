#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], pref[maxn], suff[maxn];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        pref[i] = gcd(a[i], pref[i - 1]);
    }
    for(int i = n; i > 0; i--) {
        suff[i] = gcd(a[i], suff[i + 1]);
    }
    vector<int> tmp;
    for(int i = 1; i <= n; i++) {
        tmp.push_back(gcd(suff[i + 1], pref[i - 1]));
    }
    cout << *max_element(tmp.begin(), tmp.end());
}