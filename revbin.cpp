#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total_ones = 0;
    for (char c : s) {
        if (c == '1') total_ones++;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = (s[i] == '0') ? 1 : -1;
    }

    int max_gain = 0, current_gain = 0;
    for (int i = 0; i < n; i++) {
        current_gain = max(arr[i], current_gain + arr[i]);
        max_gain = max(max_gain, current_gain);
    }

    if (total_ones == n) {
        cout << n - 1 << endl;
    } else {
        cout << total_ones + max_gain << endl;
    }

    return 0;
}