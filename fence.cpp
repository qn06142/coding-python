#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    int minHeight = INT_MAX;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int newHeight = a[i] + b[j];
            if(newHeight > a[0]) {
                a[i] = newHeight;
                minHeight = min(minHeight, newHeight);
            }
        }
    }

    cout << minHeight << endl;

    return 0;
}
