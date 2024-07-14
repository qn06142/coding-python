#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
//#define DEBUG 
int main() {
    #define int long long
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    #ifdef DEBUG
    // Debug: Initial input arrays
    cout << "Initial arrays:" << endl;
    cout << "a: ";
    for (const auto& val : a) cout << val << " ";
    cout << endl;

    cout << "b: ";
    for (const auto& val : b) cout << val << " ";
    cout << endl;
    #endif

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    #ifdef DEBUG
    // Debug: Sorted arrays
    cout << "Sorted arrays:" << endl;
    cout << "a: ";
    for (const auto& val : a) cout << val << " ";
    cout << endl;

    cout << "b: ";
    for (const auto& val : b) cout << val << " ";
    cout << endl;
    #endif

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int p = (a[i] + k - 1) / k;
        int q = (b[i] + k - 1) / k;
        a[i] = p * k - a[i];
        b[i] = q * k - b[i];
        ans += p + q;

        #ifdef DEBUG
        // Debug: After calculating p and q
        cout << "After iteration " << i << ":" << endl;
        cout << "a[i]: " << a[i] << ", b[i]: " << b[i] << ", p: " << p << ", q: " << q << ", ans: " << ans << endl;
        #endif
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    #ifdef DEBUG
    // Debug: Sorted adjusted arrays
    cout << "Sorted adjusted arrays:" << endl;
    cout << "a: ";
    for (const auto& val : a) cout << val << " ";
    cout << endl;

    cout << "b: ";
    for (const auto& val : b) cout << val << " ";
    cout << endl;
    #endif

    map<int, int> mp;
    for(int i = 0; i < n; i++) { // Changed index to start from 0
        mp[b[i]] ++;
    }

    #ifdef DEBUG
    // Debug: Map content after initialization
    cout << "Map content after initialization:" << endl;
    for (const auto& pair : mp) {
        cout << "b[i]: " << pair.first << ", count: " << pair.second << endl;
    }
    #endif

    for(int i = 0; i < n; i++) { // Changed index to start from 0
        bool found = false;
        while(not found) {
            auto it = mp.lower_bound(k - a[i]);
            if(it == mp.end()) break;
            if(it->second == 0) {
                mp.erase(it);
                continue;
            }
            
            ans -= (a[i] + it->first) / k;
            mp[it->first] --;
            found = true;

            #ifdef DEBUG
            // Debug: After processing map entry
            cout << "After processing map entry for a[" << i << "]:" << endl;
            cout << "a[i]: " << a[i] << ", it->first: " << it->first << ", ans: " << ans << endl;
            #endif
        }
    }
    cout << ans << endl;

    return 0;
}
