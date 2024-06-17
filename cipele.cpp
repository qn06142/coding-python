#include "bits/stdc++.h"
using namespace std;
    
long long n, m;
const long long MXN = 100005;
    
long long a1[MXN], a2[MXN];
    
bool works(long long x) {
    long long lpt = 0;
    long long rpt = 0;
    for (long long i=0; i<n; i++) {
        long long at = a1[i];
        long long mxr = at + x;
        long long mnr = at - x;
        while (rpt < m && a2[rpt] <= mxr) {
            rpt++;
        }
        while (lpt < m && a2[lpt] < mnr) {
            lpt++;
        }
        if (lpt == rpt) {
            return false;
        }
        lpt++;
    }
    return true;
}
    
int main() {
    
    cin >> n >> m;
    
    if (n < m) {
        for (long long i=0; i<n; i++) {
            cin >> a1[i];
        }
        for (long long i=0; i<m; i++) {
            cin >> a2[i];
        }
    }
    else {
        for (long long i=0; i<n; i++) {
            cin >> a2[i];
        }
        for (long long i=0; i<m; i++) {
            cin >> a1[i];
        }
        swap(n, m);
    }
    
    sort(a1, a1+n); sort(a2, a2+m);
    
    long long low = 0;
    long long high = INT_MAX;
    
    while (low + 1 < high) {
        long long mid = (low + high) / 2;
        bool res = works(mid);
        if (res) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    
    if (works(low)) {
        cout << low << endl;
    }
    else {
        cout << high << endl;
    }
    
    
    
}