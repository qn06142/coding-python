#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    long long T;
    cin >> N >> T;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long best_sum = -1e18; 
    double min_diff = 1e18;     

    for (int i = 0; i < N - 2; i++) {
        int j = i + 1, k = N - 1;
        while (j < k) {
            long long sum = A[i] + A[j] + A[k];
            double avg_diff = fabs((double)sum / 3.0 - T);

            if (avg_diff < min_diff || (avg_diff == min_diff && sum > best_sum)) {
                min_diff = avg_diff;
                best_sum = sum;
            }

            if ((double)sum / 3.0 < T) {
                j++;
            } else {
                k--;
            }
        }
    }

    cout << best_sum << '\n';
    return 0;
}
