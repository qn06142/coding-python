#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int n, k;
vector<vector<int>> combinations;

void generate_combinations(vector<int>& comb, int start) {
    if (comb.size() == k) {
        combinations.push_back(comb);
        return;
    }

    for (int i = start; i <= n; ++i) {
        comb.push_back(i);
        generate_combinations(comb, i + 1);
        comb.pop_back();
    }
}

bool isPerfectSquare(long long x) {
    long long s = (long long)sqrt(x);
    return s * s == x;
}

int main() {
    cin >> n >> k;
    vector<int> comb;
    generate_combinations(comb, 1);

    sort(combinations.begin(), combinations.end());

    int perfectSquareCount = 0;

    for (const auto& c : combinations) {
        for (int num : c) {
            cout << num << " ";
        }
        cout << endl;

        long long product = 1;
        for (int num : c) {
            product *= num;
        }

        if (isPerfectSquare(product)) {
            ++perfectSquareCount;
        }
    }

    cout << perfectSquareCount << endl;

    return 0;
}
