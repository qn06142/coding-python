#include <iostream>

using namespace std;
#define int long long
int find_jumps(int L, int m, int n) {
    int k = 0;
    int total_distance = 0;

    while (total_distance <= L) {
        k++;
        total_distance += m + (k - 1) * n;
    }

    return k;
}

signed main() {
    int L, m, n;
    
    cin >> L;
    
    cin >> m;

    cin >> n;

    int k = find_jumps(L, m, n);
    cout << k << endl;

    return 0;
}
