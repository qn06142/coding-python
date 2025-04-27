#include <iostream>
#include <set>
#include <vector>
using namespace std;
 
const long long mod = 1000000007;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    long long ans = 0;
    // Iterate over every subarray starting at index i
    for (int i = 0; i < n; i++){
        multiset<int> window;
        // Extend the subarray to j
        for (int j = i; j < n; j++){
            window.insert(a[j]);
            // The minimum is the first element, the maximum is the last element in the multiset
            int mini = *window.begin();
            int maxi = *window.rbegin();
            ans = (ans + (long long)mini * maxi) % mod;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
