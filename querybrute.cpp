#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform a rotation by moving the last element to the front
void rotateArray(vector<int>& arr) {
    if (!arr.empty()) {
        int last = arr.back();
        arr.pop_back();
        arr.insert(arr.begin(), last);
    }
}

// Function to find the maximum number of 1's in any subarray of length K
int maxOnesInSubarray(const vector<int>& arr, int K) {
    int N = arr.size();
    if (K > N) return 0;  // Return 0 if K > N, as no valid subarray can be formed

    int maxCount = 0, currentCount = 0;
    
    // Calculate initial count of 1's in the first subarray of length K
    for (int i = 0; i < K; i++) {
        currentCount += arr[i];
    }
    maxCount = currentCount;
    
    // Slide the window across the array and update counts
    for (int i = K; i < arr.size(); i++) {
        currentCount += arr[i] - arr[i - K];
        maxCount = max(maxCount, currentCount);
    }
    return maxCount;
}

int main() {
    int N, K, P;
    cin >> N >> K >> P;
    vector<int> arr(N);
    
    // Read array elements
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    // Read queries
    for (int i = 0; i < P; i++) {
        char query;
        cin >> query;
        
        if (query == '!') {
            // Perform the rotation
            rotateArray(arr);
        } else if (query == '?') {
            // Find and output the maximum number of 1's in any subarray of length K
            cout << maxOnesInSubarray(arr, K) << endl;
        }
    }

    return 0;
}
