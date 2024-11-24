#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string S, A;
    cin >> S >> A;

    string A_copy = A;
    int min_operations = A.size();
    do {
        int operations = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] != A_copy[i]) {
                operations += 1;
            }
        }
        min_operations = min(min_operations, operations);
    } while (next_permutation(A_copy.begin(), A_copy.end()));
    cout << min_operations;
    return 0;
}
