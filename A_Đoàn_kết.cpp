#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    if(!(cin>>n>>k)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int g = gcd(n,k);
    long long ans = 0;
    for(int r=0; r<g; ++r){
        vector<long long> v;
        int idx = r;
        // walk the cycle (wrap with modulo)
        do {
            v.push_back(a[idx]);
            idx = (idx + k) % n;
        } while (idx != r);

        sort(v.begin(), v.end());
        long long med = v[v.size()/2];
        for(long long x : v) ans += llabs(x - med);
    }
    cout << ans << '\n';
    return 0;
}
