#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

const int N = 1e5 + 5;

int logn[N];
int maxSparseTable[N][20];
int minSparseTable[N + 5][20];

void buildSparseTable(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i <= n; i++) {
        maxSparseTable[i][0] = minSparseTable[i][0] = nums[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            maxSparseTable[i][j] = max(maxSparseTable[i][j - 1], maxSparseTable[i + (1 << (j - 1))][j - 1]);
            minSparseTable[i][j] = min(minSparseTable[i][j - 1], minSparseTable[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int getMax(int l, int r) {
    int j = logn[r - l + 1];
    return max(maxSparseTable[l][j], maxSparseTable[r - (1 << j) + 1][j]);
}

int getMin(int l, int r) {
    int j = logn[r - l + 1];
    return min(minSparseTable[l][j], minSparseTable[r - (1 << j) + 1][j]);
}

int min_pieces(int n, int s, int l, vector<int> nums) {
    buildSparseTable(nums);
    vector<int> f(n + 1, INT_MAX);
    f[0] = 0;
    int j = 0;
    for (int i = 1; i <= n; i++) {
        while((i - j >= l && (getMax(j + 1, i) - getMin(j + 1, i) > s || f[j] == INT_MAX))) j++;
        if(i - j < l) f[i] = INT_MAX;
        else f[i] = f[j] + 1;
    }
    return f[n] == INT_MAX ? -1 : f[n];
}

int main() {
    logn[1] = 0;
    for (int i = 2; i < N; i++)
        logn[i] = logn[i / 2] + 1;

    int n, s, l;
    cin >> n >> s >> l;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    cout << min_pieces(n, s, l, nums) << endl;
    return 0;
}