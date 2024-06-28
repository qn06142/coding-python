#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countPairsWithSum(const vector<int>& A, int x) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int num : A) {
        int complement = x - num;
        if (freq.find(complement) != freq.end()) {
            count += freq[complement];
        }
        freq[num]++;
    }

    return count;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cout << countPairsWithSum(A, x) << endl;

    return 0;
}
