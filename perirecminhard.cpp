#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int rect(vector<int>& heights) {
    int m = heights.size() - 1; 
    int ans = 0;
    stack<int> stacc1, stacc2;
    vector<int> r(m + 1), l(m + 1);

    for (int i = 1; i <= m; ++i) {
        while (!stacc1.empty() && heights[stacc1.top()] >= heights[i]) {
            stacc1.pop();
        }
        l[i] = stacc1.empty() ? 1 : stacc1.top() + 1;
        stacc1.push(i);
    }

    for (int i = m; i >= 1; --i) {
        while (!stacc2.empty() && heights[stacc2.top()] >= heights[i]) {
            stacc2.pop();
        }
        r[i] = stacc2.empty() ? m : stacc2.top() - 1;
        stacc2.push(i);
    }

    for (int i = 1; i <= m; ++i) {
        int width = r[i] - l[i] + 1;
        if(heights[i])
        ans = max(ans, (heights[i] + width) * 2);
    }/*
    cout << endl;
    for (int i = 1; i <= m; ++i) cout << l[i] << ' ';
    cout << endl;
    for (int i = 1; i <= m; ++i) cout << r[i] << ' ';
    cout << endl;
    cout << ans << endl;;
    */
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> heights(m + 1, 0); 
    int ans = 0;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            char tmp;
            cin >> tmp;
            if ((tmp - '0') == 0) {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }

        int perimeter = rect(heights);
        ans = max(ans, perimeter);
    }

    cout << ans << endl;

    return 0;
}