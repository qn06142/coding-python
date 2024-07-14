#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define int long long
int countValidPairs(const vector<int>& arr, int n) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int num : arr) {
        freq[num]++;
    }

    for (const auto& p1 : freq) {
        int num1 = p1.first;
        int freq1 = p1.second;

        if ((num1 ^ num1) <= 1) {
            count += (freq1 * (freq1 - 1)) / 2;
        }

        for (const auto& p2 : freq) {
            int num2 = p2.first;
            if (num1 < num2 && (num1 ^ num2) <= 1) {
                count += freq1 * p2.second;
            }
        }
    }

    return count;
}

signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << countValidPairs(arr, n) << endl;
    return 0;
}