#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    long long k;
    cin >> n >> k;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    long long max_freq = 1;
    long long best_value = a[0];
    long long sum = 0;  // To track the sum of elements in the window
    
    int left = 0;
    for (int right = 0; right < n; ++right) {
        sum += a[right];
        
        // While the cost of making all elements in the current window equal to a[right] exceeds k
        while (a[right] * (right - left + 1) - sum > k) {
            sum -= a[left];  // Shrink the window from the left
            ++left;
        }
        
        // Update if the current window is the largest we can make equal
        if (right - left + 1 > max_freq) {
            max_freq = right - left + 1;
            best_value = a[right];
        }
    }
    
    cout << max_freq << " " << best_value << "\n";
    return 0;
}
