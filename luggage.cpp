#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, p;
vector<long long> vc;
long long a[(int) 1e5 + 5], b[(int) 1e5 +5];
bool check(long long T) {
    vc.clear();
    for(int i = 1; i <= n; i++) {
        long long x = max(0LL, T - b[i])/a[i];
        vc.push_back(x);
    }
    long long all = 0; // Change type to long long
    sort(vc.begin(), vc.end(), greater<int>());
    for(int i = 0; i < min((int) vc.size(), m); i++) {
        all += vc[i];
    }
    if(all >= p) return true;
    else return false;
}

int main() {
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    long long L = 0, R = 1e18 - 1;
    while (L <= R) {
        long long mid = (L + R) / 2;
        if (check(mid)) R = mid - 1;
        else L = mid + 1;
    }
    cout << L << endl;
    return 0;
}
