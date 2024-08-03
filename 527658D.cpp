#include <iostream>
#include <vector>

using namespace std;

int count_valid_permutations(int n, vector<int>& arr, vector<bool>& used, int pos) {
    if (pos == 2 * n) {
        return 1;
    }

    int count = 0;
    for (int i = 2; i <= 2 * n; ++i) {
        if (!used[i]) {
            if ((arr[pos - 1] + i) % 2 == 1) { // check if the sum is odd
                arr[pos] = i;
                used[i] = true;
                count += count_valid_permutations(n, arr, used, pos + 1);
                used[i] = false;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(2 * n + 1, 0);
    vector<bool> used(2 * n + 1, false);

    // Start with 1 in the first position
    arr[0] = 1;
    used[1] = true;

    int result = count_valid_permutations(n, arr, used, 1);
    cout << result << endl;

    return 0;
}
