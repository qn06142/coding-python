#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const vector<int>& a, int N, int K, int median) {
    vector<int> b(N + 1, 0);
    for (int i = 1; i <= N; ++i) {

        b[i] = b[i - 1] + (a[i - 1] <= median ? 1 : -1);
    }
    int min_prefix = 0;
    for (int i = K; i <= N; ++i) {

        if (b[i] - min_prefix >= 0) return true;
        min_prefix = min(min_prefix, b[i - K + 1]);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int low = 1, high = N, result = N; 
    while (low <= high) {
        int mid = (low + high) / 2;

        if (check(a, N, K, mid)) {
            result = mid;
            high = mid - 1;  
        } else {
            low = mid + 1;
        }
    }

    cout << result << "\n";
    return 0;
}