#include<bits/stdc++.h>

using namespace std;
int n;
int themap[(int) 5e5 + 5];
int a[(int) 5e5 + 5];
vector<int> divs;
int calc(int x) {

    int l = 1, worst = 1e9;
    int count = 0;
    for(int i = 1; i <= n; i++) {
        
        if(themap[a[i]] == 0) {
            themap[a[i]]++;
            count++;
        }
        if(i % x == 0) {
            worst = min(worst, count);
            count = 0;
            while(l <= i) {
                themap[a[l]] = 0;
                l++;
            }
            
        }
        //cout << i << " " << worst << endl;;
        
    }
    return worst;
}
/*
vector<int> cpr(a + 1, a + n + 1);
sort(ALL(cpr));
cpr.resize(unique(ALL(cpr)) - cpr.begin());
for(int i = 1; i <= n; i++) a[i] = lower_bound(ALL(cpr), a[i]) - cpr.begin() + 1;
ALL(cpr) = cpr.begin(), cpr.end()
*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> compress(a + 1, a + n + 1);
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
    for(int i = 1; i <= n; i++) {
        a[i] = lower_bound(compress.begin(), compress.end(), a[i]) - compress.begin() + 1;
    }

    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            divs.push_back(i);
            if((n / i) != i) divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    cout << divs.size() << endl;
    for(int i:divs) {
        cout << i << " " << calc(i) << endl;
    }
}