#include<bits/stdc++.h>
using namespace std;

int maxJumpLength(vector<int>& A, int P) {
    int N = A.size();
    int i = 0, j = 0;
    int maxLen = 0;
    while (j < N) {
        if (A[j] - A[i] >= P) {
            maxLen = max(maxLen, j - i);
            i++;
        } else {
            j++;
        }
    }
    return maxLen;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int P = 3;
    cout << maxJumpLength(A, P) << endl;
    return 0;
}
