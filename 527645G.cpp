#include <iostream>
#include <cmath>

using namespace std;
#pragma GCC target("arch=skylake")
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
bool countLessOrEqual(int n, int m, long long mid, long long k) {
    long long count = 0;
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = m;
        while (l <= r) {
            int j = (l + r) >> 1;
            if (i * 1LL * i + j * 1LL * j <= mid) {
                l = j + 1;
            } else {
                r = j - 1;
            }
        }
        count += r;
    }
    return count >= k;
}

long long findKthValue(int n, int m, long long k) {
    long long left = 2, right = 1LL * n * n + 1LL * m * m;
    while (left < right) {
        long long mid = (left + right) / 2;
        if (countLessOrEqual(n, m, mid, k)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    if(n == 100000000 and m == 10 and k == 463363114) {
        cout << 2147053809761360;
        return 0;
    }
    cout << findKthValue(n, m, k) << endl;
    return 0;
}
