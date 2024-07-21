#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> find_all_sums(int n, vector<int>& arr) {
    int max_sum = 0;
    for (int num : arr) {
        max_sum += num;
    }
    
    vector<bool> dp(max_sum + 1, false);
    dp[0] = true;

    for (int num : arr) {
        for (int i = max_sum; i >= num; --i) {
            if (dp[i - num]) {
                dp[i] = true;
            }
        }
    }

    vector<int> result;
    for (int i = 1; i <= max_sum; ++i) {
        if (dp[i]) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> result = find_all_sums(n, arr);

    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
