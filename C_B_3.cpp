#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VAL = 1e6;

vector<int> divs[MAX_VAL + 5];

int main() {
    // Precompute divisors
    for (int i = 1; i <= MAX_VAL; i++) {
        for (int j = i; j <= MAX_VAL; j += i) {
            divs[j].push_back(i);
        }
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long ans = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // Find the largest divisor of a[i] less than or equal to a[j]
            int largest_div = divs[a[i]][divs[a[i]].size() - 
                                        (lower_bound(divs[a[i]].begin(), divs[a[i]].end(), a[j]) - divs[a[i]].begin()) - 1];
            ans += largest_div;
        }
    }

    cout << ans << '\n';
    return 0;
}
