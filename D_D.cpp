#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;
const int MOD = 1000000007;

inline int add(int a, int b) {
    return (a + b >= MOD ? a + b - MOD : a + b);
}

inline int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

int n, m, distinctCount;
int arr[MAXN], sortedArr[MAXN], freq[MAXN];

void preprocess() {
    sort(arr, arr + n);
    memcpy(sortedArr, arr, sizeof(int) * n);
    distinctCount = unique(arr, arr + n) - arr;
    for (int j = 0; j < distinctCount; ++j) {
        freq[j] = upper_bound(sortedArr, sortedArr + n, arr[j]) - lower_bound(sortedArr, sortedArr + n, arr[j]);
    }
}

inline void pushStack(stack<pair<int, int>> &stk, int x) {
    int product = mul(x, stk.empty() ? 1 : stk.top().second);
    stk.emplace(x, product);
}

int solve() {
    if (distinctCount < m) return 0;

    stack<pair<int, int>> forwardStack, reverseStack;

    for (int j = 0; j < m; ++j) {
        pushStack(forwardStack, freq[j]);
    }

    int result = 0;
    for (int j = m; j <= distinctCount; ++j) {
        if (arr[j - 1] - arr[j - m] == m - 1) {
            int prodForward = forwardStack.empty() ? 1 : forwardStack.top().second;
            int prodReverse = reverseStack.empty() ? 1 : reverseStack.top().second;
            result = add(result, mul(prodForward, prodReverse));
        }

        if (reverseStack.empty()) {
            while (!forwardStack.empty()) {
                pushStack(reverseStack, forwardStack.top().first);
                forwardStack.pop();
            }
        }
        reverseStack.pop(); 

        pushStack(forwardStack, freq[j]);
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        preprocess();
        cout << solve() << endl;
    }
}