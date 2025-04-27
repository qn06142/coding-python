#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, L, U;
    cin >> N >> L >> U;
    vector<long long> a(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<int> dp1(N, 1);
    vector<int> dp2(N, 1);
    
    int ans = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (i - j >= L) {
                if (a[i] > a[j] && abs(a[i] - a[j]) >= U) {
                    dp1[i] = max(dp1[i], dp2[j] + 1);
                } else if (a[i] < a[j] && abs(a[i] - a[j]) >= U) {
                    dp2[i] = max(dp2[i], dp1[j] + 1);
                }
            }
        }
        ans = max(ans, max(dp1[i], dp2[i]));
    }

    cout << ans << endl;

    return 0;
}
