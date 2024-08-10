#include <bits/stdc++.h>
using namespace std;

// Function to check if the median is possible or not.
bool good(int arr[], int N, int K, int median) {
    vector<int> pre(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i - 1] + (arr[i - 1] >= median ? 1 : -1);
    }

    int mn = 0;
    for (int i = K; i <= N; i++) {
        if (pre[i] - mn > 0) return true;
        mn = min(mn, pre[i - K + 1]);
    }
    return false;
}

// Function to find the minimum median of a subarray having length at least K
int minMedian(int arr[], int N, int K) {
    int l = 1, r = N, result = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (good(arr, N, K, mid)) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];

    cout << minMedian(arr, N, K) << endl;
    return 0;
}
