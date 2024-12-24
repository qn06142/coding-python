#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long i = 0, j = 0, points = 0;

    
    while (j < n && i < n) {
        if (b[j] > a[i]) {
            ++points; 
            ++i;      
        }
        ++j;
    }

    cout << points << '\n';
    return 0;
}
