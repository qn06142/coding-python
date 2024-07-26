#include <iostream>
#include <vector>
using namespace std;

bool is_valid_length(const vector<int>& A, int N, long long K, int length) {
    long long current_sum = 0;

    for (int i = 0; i < length; ++i) {
        current_sum += A[i];
    }

    if (current_sum < K) {
        return true;
    }

    for (int i = length; i < N; ++i) {
        current_sum += A[i] - A[i - length];
        if (current_sum < K) {
            return true;
        }
    }
    return false;
}

int main() {

    int N;
    long long K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int left = 1, right = N;
    int max_length = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (is_valid_length(A, N, K, mid)) {
            max_length = mid; 
            left = mid + 1;
        } else {
            right = mid - 1; 
        }
    }

    cout << max_length << endl;
    return 0;
}