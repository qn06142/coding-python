#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int max_sub_arr(const vector<int>& arr) {
    int max_sum = INT_MIN, current_sum = 0;
    for (int x : arr) {
        current_sum = max(x, current_sum + x);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> m(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    
    int result = INT_MIN;
    
    for (int maxVal = -500; maxVal <= 500; ++maxVal) {
        vector<int> transformed;
        
        for (int i = 0; i < n; ++i) {
            if (m[i] > maxVal) {
                transformed.push_back(INT_MIN / 2);  // Effectively negative infinity
            } else {
                transformed.push_back(m[i]);
            }
        }
        
        int max_sum = max_sub_arr(transformed);
        if (max_sum != INT_MIN / 2) {
            result = max(result, max_sum - maxVal);
        }
    }
    
    cout << result << endl;
    
    return 0;
}
