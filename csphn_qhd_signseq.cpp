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

    vector<int> L_array(N, 1);
    vector<int> P_array(N, 1);
    
    int maxLength = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (i - j >= L) {
                if (a[i] > a[j] && abs(a[i] - a[j]) >= U) {
                    L_array[i] = max(L_array[i], P_array[j] + 1);
                } else if (a[i] < a[j] && abs(a[i] - a[j]) >= U) {
                    P_array[i] = max(P_array[i], L_array[j] + 1);
                }
            }
        }
        maxLength = max(maxLength, max(L_array[i], P_array[i]));
    }

    cout << maxLength << endl;

    return 0;
}
