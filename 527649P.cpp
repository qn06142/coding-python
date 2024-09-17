#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n), r(m), water(m, 0), prefix(m, 0);
    
    // Input water amounts
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Input reservoir capacities and calculate prefix sums
    for (int i = 0; i < m; ++i) {
        cin >> r[i];
        prefix[i] = r[i] + (i > 0 ? prefix[i - 1] : 0);
    }
    
    // Process each water input
    for (int i = 0; i < n; ++i) {
        long long water_left = a[i];
        
        // Binary search to find the last reservoir that can hold water
        int low = 0, high = m - 1, idx = m;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (prefix[mid] <= water_left) {
                low = mid + 1;
            } else {
                idx = mid;
                high = mid - 1;
            }
        }
        
        // Distribute water across the reservoirs
        if (idx > 0) {
            water[idx - 1] += water_left - prefix[idx - 1]; // Excess water in the reservoir idx
            water_left = prefix[idx - 1];
        }
        
        // Add water to the reservoirs up to the idx found by binary search
        for (int j = 0; j < idx; ++j) {
            water[j] = r[j];
        }
    }
    
    // Output the final water amounts in each reservoir
    for (int i = 0; i < m; ++i) {
        cout << water[i] << " ";
    }
    
    return 0;
}
