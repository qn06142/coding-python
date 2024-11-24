#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long
int countPairsWithMaxSum(const vector<int>& A, int m) {
    int left = 0;
    int right = A.size() - 1;
    int count = 0;

    while (left < right) {
        if (A[left] + A[right] <= m) {
            count += (right - left);
            left++;
        } else {
            right--;
        }
    }

    return count;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    
    cin >> n >> m;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    cout << countPairsWithMaxSum(A, m) << endl;

    return 0;
}
