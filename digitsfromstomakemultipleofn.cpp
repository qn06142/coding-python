#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_smallest_multiple(int n, vector<int>& S) {
    sort(S.begin(), S.end());  

    vector<int> dp(n, 1e9);
    vector<pair<int, int>> result(n, {-1, 0});

    for (int digit : S) {
        if (digit != 0) {
            int mod = digit % n;
            dp[mod] = 1;
            result[mod] = {-1, digit};
        }
    }

    vector<int> queue;
    for (int digit : S) {
        if (digit != 0) {
            queue.push_back(digit % n);
        }
    }
    for (int i = 0; i < queue.size(); ++i) {
        int u = queue[i];
        for (int digit : S) {
            int v = (u * 10 + digit) % n;
            if (dp[u] + 1 < dp[v]) {
                dp[v] = dp[u] + 1;
                queue.push_back(v);
                result[v] = {u, digit};
            }
        }
    }

    if (dp[0] > 1e9) {
        return -1;
    } else {
        vector<int> ans;
        int idx = 0;
        while (idx != -1) {
            ans.push_back(result[idx].second);
            idx = result[idx].first;
        }
        reverse(ans.begin(), ans.end());
        int res = 0;
        for (int digit : ans) {
            res = res * 10 + digit;
        }
        return res;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> S;
    string s;
    cin >> s;
    for (char c : s) {
        S.push_back(c - '0');
    }
    int result = find_smallest_multiple(n, S);
    cout << result << endl;
    return 0;
}