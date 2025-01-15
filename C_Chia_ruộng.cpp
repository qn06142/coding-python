#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int countWays(vector<int>& areas, vector<int>& used, int index, int sum1, int sum2, int sum3, int target) {
    if (index == areas.size()) {
        return (sum1 == target && sum2 == target && sum3 == target) ? 1 : 0;
    }

    int ways = 0;

    if (sum1 + areas[index] <= target) {
        sum1 += areas[index];
        ways += countWays(areas, used, index + 1, sum1, sum2, sum3, target);
        sum1 -= areas[index];
    }

    if (sum2 + areas[index] <= target) {
        sum2 += areas[index];
        ways += countWays(areas, used, index + 1, sum1, sum2, sum3, target);
        sum2 -= areas[index];
    }

    if (sum3 + areas[index] <= target) {
        sum3 += areas[index];
        ways += countWays(areas, used, index + 1, sum1, sum2, sum3, target);
        sum3 -= areas[index];
    }

    return ways;
}

int main() {
    int n;
    cin >> n;
    vector<int> areas(n);
    int total = 0;

    for (int i = 0; i < n; ++i) {
        cin >> areas[i];
        total += areas[i];
    }

    if (total % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    int target = total / 3;
    vector<int> used(n, -1);

    sort(areas.rbegin(), areas.rend());

    int result = countWays(areas, used, 0, 0, 0, 0, target);

    if (result > 0) {
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}