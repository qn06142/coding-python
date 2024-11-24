#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solve(int N, vector<int>& A, int Q, vector<int>& queries) {

    sort(A.begin(), A.end());

    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i - 1];
    }

    vector<int> results;
    for (int K : queries) {

        int left = 0, right = N;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (prefix_sum[mid] < static_cast<long long>(K) * mid) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        results.push_back(left);
    }

    return results;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int Q;
    cin >> Q;
    vector<int> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i];
    }

    vector<int> results = solve(N, A, Q, queries);
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}