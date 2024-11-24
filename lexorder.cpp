#include <iostream>
#include <vector>

using namespace std;

vector<long long> computeFactorials(int n) {
    vector<long long> factorials(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        factorials[i] = factorials[i - 1] * i;
    }
    return factorials;
}

vector<int> kthPermutation(int n, long long k) {
    vector<long long> factorials = computeFactorials(n);
    vector<int> available(n);
    vector<int> permutation;

    for (int i = 0; i < n; ++i) {
        available[i] = i + 1;
    }

    k--;  
    for (int i = 0; i < n; ++i) {
        long long base = factorials[n - 1 - i];
        int index = k / base;
        permutation.push_back(available[index]);
        available.erase(available.begin() + index);
        k %= base;
    }

    return permutation;
}

long long permutationToNumber(const vector<int>& perm) {
    int n = perm.size();
    vector<long long> factorials = computeFactorials(n);
    vector<bool> used(n + 1, false);
    long long number = 0;

    for (int i = 0; i < n; ++i) {
        int smaller = 0;
        for (int j = 1; j < perm[i]; ++j) {
            if (!used[j]) {
                smaller++;
            }
        }
        number += smaller * factorials[n - 1 - i];
        used[perm[i]] = true;
    }

    return number + 1;  
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> before(n);
    for(int i = 0; i < n; i++) cin >> before[i];
    vector<int> permutation = kthPermutation(n, permutationToNumber(before) + k);
    for (int num : permutation) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}