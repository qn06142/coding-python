#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    freopen("KPREFIX.INP", "r", stdin);
    freopen("KPREFIX.OUT", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long prefix_sum = 0;
    int result = 0;

    for (int i = 1; i <= n; i++) {

        prefix_sum += a[i-1];
        int mod_value = prefix_sum % k;
        if (mod_value < 0) mod_value += k;  

        if (mod_value == 0) {
            result = i;
        }

        int x = (mod_value == 0) ? 0 : k - mod_value;

        if (i >= x) {
            result = max(result, i);  
        }
    }

    cout << result << endl;
    return 0;
}