#include <iostream>
#include <vector>
using namespace std;

int longestBitonicSubarray(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    // Length of increasing subarray ending at all indexes
    vector<int> inc(n, 1);
    // Length of decreasing subarray starting at all indexes
    vector<int> dec(n, 1);

    // Fill inc[] from left to right
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1])
            inc[i] = inc[i - 1] + 1;

    // Fill dec[] from right to left
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > arr[i + 1])
            dec[i] = dec[i + 1] + 1;

    // Find the length of maximum length bitonic subarray
    int maxLen = inc[0] + dec[0] - 1;
    for (int i = 1; i < n; i++)
        if (inc[i] + dec[i] - 1 > maxLen)
            maxLen = inc[i] + dec[i] - 1;

    return maxLen;
}

int main() {
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout << longestBitonicSubarray(arr) << endl;
    
    return 0;
}
