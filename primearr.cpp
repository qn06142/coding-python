#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<bool> sieve(int max_num) {
    vector<bool> is_prime(max_num + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= max_num; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= max_num; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return is_prime;
}

vector<int> transform_array(const vector<int>& a, const vector<bool>& is_prime) {
    vector<int> transformed;
    for (const int& num : a) {
        if (num == 1) {
            transformed.push_back(0);
        } else if (is_prime[num]) {
            transformed.push_back(1);
        } else {
            transformed.push_back(-1);
        }
    }
    return transformed;
}

int process_test_case(int n, int e, const vector<int>& a, const vector<bool>& is_prime) {
    //cout << endl;
    vector<int> transformed = transform_array(a, is_prime);
    
    vector<int> r(n, 0), l(n, 0);
    
    for (int i = n - 1; i >= 0; i--) {
        if (transformed[i] != 0) {
            r[i] = 0;
        } else {
            r[i] = ((i + e) >= n) ? 1 : r[i + e] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (transformed[i] != 0) {
            l[i] = 0;
        } else {
            l[i] = (i < e) ? 1 : l[i - e] + 1;
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (transformed[i] == 1) {
            int left = (i < e) ? 0 : l[i - e];
            int right = (i + e >= n) ? 0 : r[i + e];
            count += (left + 1) * (right + 1) - 1;
            //cout << left << ' ' << right << ' ' << i << endl;
        }
        
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    vector<pair<int, pair<int, vector<int>>>> test_cases;
    int max_n = 0, max_a = 0;

    for (int i = 0; i < t; ++i) {
        int n, e;
        cin >> n >> e;
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
            max_a = max(max_a, a[j]);
        }
        test_cases.push_back({n, {e, a}});
        max_n = max(max_n, n);
    }

    int upper_limit = max(max_n * max_a, 1000000);
    vector<bool> is_prime = sieve(upper_limit);

    for (const auto& test_case : test_cases) {
        int n = test_case.first;
        int e = test_case.second.first;
        const vector<int>& a = test_case.second.second;
        cout << process_test_case(n, e, a, is_prime) << "\n";
    }

    return 0;
}
