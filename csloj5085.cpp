#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;

int main() {
    int n;
    LL MAX = -9999999999;

    vector<LL> a, t3, T1, T2, T1MAX;

    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    t3.resize(n);
    for (int i = 2; i < n; i++) t3[i] = a[i] + a[i - 1] + a[i - 2];

    T1.resize(n);
    T1[2] = t3[2];
    for (int i = 3; i < n; i++) T1[i] = max(t3[i], T1[i - 3] + t3[i]);

    T2.resize(n);
    T2[n - 3] = t3[n - 1];  // = a[n-3] + a[n-2] + a[n-1];
    for (int i = n - 4; i >= 0; i--) T2[i] = max(t3[i + 2], T2[i + 3] + t3[i + 2]);

    T1MAX.resize(n);
    T1MAX[2] = T1[2];
    for (int i = 3; i < n; i++) T1MAX[i] = max(T1MAX[i - 1], T1[i]);

    for (int j = 3; j <= n - 3; j++) MAX = max(MAX, T2[j] + T1MAX[j - 1]);

    cout << MAX << endl;

    return 0;
}
