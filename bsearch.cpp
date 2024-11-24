#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    while(q--){
        int i;
        cin >> i;
        auto it = lower_bound(a.begin(), a.end(), i);
        if(it == a.end() || *it != i){
            cout << -1 << "\n";
        } else {
            cout << i << "\n";
        }
    }

    return 0;
}
