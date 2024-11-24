#include <bits/stdc++.h>
using namespace std;

// Function to check if the median is possible or not.
bool good(int arr[], int N, int K, int median) {
    vector<int> pre(N);
    for (int i = 0; i < N; i++) {
        pre[i] = (arr[i] >= median) ? 1 : -1;
        if (i > 0) pre[i] += pre[i - 1];
    }

    int mx = pre[K - 1], mn = 0;
    for (int i = K; i < N; i++) {
        mn = min(mn, pre[i - K]);
        mx = max(mx, pre[i] - mn);
    }
    return mx > 0;
}

// Function to find the maximum median of a subarray having length at least K
int maxMedian(int arr[], int N, int K) {
    int l = 1, r = N + 1, mx_median = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (good(arr, N, K, mid)) {
            mx_median = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return mx_median;
}

int main() {
    int N, K;
    cin >> N >> K;
    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];

    cout << maxMedian(arr, N, K) << endl;
    return 0;
}
