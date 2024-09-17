#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    
    // Reading input values into the array `a`
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    // Initial range for binary search (lo, hi)
    long long lo = 2, hi = 200005; 
    
    // Sort the array `a` in ascending order
    sort(a.begin(), a.end());
    
    // Binary search to find the maximum threshold `lo` for handshake sum
    while (hi - lo > 1) {
        long long mid = (hi + lo) / 2;  // midpoint of current search range
        long long r = 0;  // pointer to find valid pairs
        long long cnt = 0;  // count of pairs with sum >= `mid`
        
        // Count how many pairs have sum >= `mid`
        for(int i = n - 1; i >= 0; i--){
            while (r < n && a[i] + a[r] < mid) {
                r++;  // move right pointer until sum >= mid
            }
            cnt += n - r;  // all pairs (i, r to n-1) are valid
        }
        
        // Adjust search range based on whether the count meets the requirement
        if (cnt >= m) {
            lo = mid;  // valid threshold, try for larger values
        } else {
            hi = mid;  // too large, reduce the threshold
        }
    }
    
    // Now that we have determined `lo`, we proceed to calculate total happiness
    long long r = 0;
    vector<long long> sum(n + 1, 0);  // prefix sum array
    
    // Compute the prefix sums
    for(int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }
    
    long long ans = 0;  // variable to store the total happiness
    long long cnt = 0;  // variable to count how many valid pairs we process
    
    // Calculate the total happiness for pairs with sum >= `lo`
    for(int i = n - 1; i >= 0; i--) {
        while (r < n && a[i] + a[r] < lo) {
            r++;  // move right pointer until sum >= lo
        }
        
        if (r == n) break;  // if no valid pairs are left, break
        
        ans += a[i] * (n - r) + (sum[n] - sum[r]);  // add happiness for valid pairs
        cnt += n - r;  // count the number of valid pairs
    }
    
    // If we have counted fewer than `m` pairs, add the remaining pairs with sum = `lo`
    ans += (m - cnt) * lo;
    
    // Output the total happiness
    cout << ans << endl;
}
