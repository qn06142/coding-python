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
    sort(a.begin(), a.end());

    int left = lower_bound(a.begin(), a.end(), q) - a.begin();
    int right = upper_bound(a.begin(), a.end(), q) - a.begin();
    int tmp = right - left;
    cout << tmp << "\n";

    return 0;
}
