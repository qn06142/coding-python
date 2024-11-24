#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

double variance(int l, int r, const vector<long long>& S, const vector<long long>& S2) {
    int n = r - l + 1;
    if (n == 0) return 0;
    long long sum_elements = S[r] - S[l-1];
    long long sum_squares = S2[r] - S2[l-1];
    double mean = (double)sum_elements / n;
    double var = (double)sum_squares / n - mean * mean;
    return var;
}

double min_variance_partition(int N, int K, const vector<int>& A) {
    vector<long long> S(N+1, 0), S2(N+1, 0);

    for (int i = 1; i <= N; ++i) {
        S[i] = S[i-1] + A[i-1];
        S2[i] = S2[i-1] + (long long)A[i-1] * A[i-1];
    }

    vector<vector<double>> dp(N+1, vector<double>(K+1, numeric_limits<double>::infinity()));
    dp[0][0] = 0;

    for (int k = 1; k <= K; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int l = 0; l < i; ++l) {
                dp[i][k] = min(dp[i][k], dp[l][k-1] + variance(l+1, i, S, S2));
            }
        }
    }

    return dp[N][K];
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    double result = min_variance_partition(N, K, A);
    cout << fixed << setprecision(5) << result << endl;

    return 0;
}
