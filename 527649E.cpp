#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to check if there is a subarray with median >= median_candidate
bool canFindSubarrayWithMedian(const vector<int>& a, int K, int median_candidate) {
    int N = a.size();
    vector<int> prefixSum(N + 1, 0);
    int minPrefix = 0;

    for (int i = 0; i < N; ++i) {
        // Transform the array values
        prefixSum[i + 1] = prefixSum[i] + (a[i] >= median_candidate ? 1 : -1);
        if (i + 1 >= K) {
            // Check if there is a valid prefix sum
            if (prefixSum[i + 1] - minPrefix >= (i + 1 - (i + 1 - K + 1))) {
                return true;
            }
            // Update the minimum prefix sum seen
            minPrefix = min(minPrefix, prefixSum[i + 1 - K + 1]);
        }
    }
    return false;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    // Sort the array to use binary search on the median value
    sort(a.begin(), a.end());
    
    int low = a[0], high = a[N - 1];
    int result = low;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canFindSubarrayWithMedian(a, K, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
