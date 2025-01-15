#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int bruteForceSolution(int n, string s) {
    int max_ones = 0;

    // Try flipping every substring
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string flipped = s;

            // Flip substring [i, j]
            for (int k = i; k <= j; k++) {
                flipped[k] = (flipped[k] == '0') ? '1' : '0';
            }

            // Count the number of 1's in the modified string
            int current_ones = count(flipped.begin(), flipped.end(), '1');
            max_ones = max(max_ones, current_ones);
        }
    }

    return max_ones;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    cout << bruteForceSolution(n, s) << endl;

    return 0;
}
