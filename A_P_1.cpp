#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int MAXN = 1005;

int n, m;
int a[MAXN][MAXN];
int s[MAXN][MAXN];

typedef long long llint;

struct RectangleInfo {
    int count;
    int value;
    int height;
    llint areaSum;
    RectangleInfo(int _count = 0, int _value = 0, int _height = 0, llint _areaSum = 0)
        : count(_count), value(_value), height(_height), areaSum(_areaSum) {}
};

llint ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    // Input grid values
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    // Process each row
    for (int i = 0; i < n; ++i) {
        stack<RectangleInfo> S;
        S.push(RectangleInfo(0, -1, 0, 0));  // Initial dummy entry

        for (int j = 0; j < m; ++j) {
            s[i][j] = 1;

            // If current cell matches the one above, increase the height
            if (i > 0 && a[i-1][j] == a[i][j])
                s[i][j] += s[i-1][j];

            int combinedCount = 1;
            // Combine rectangles with the same value and greater height
            while (S.top().value == a[i][j] && S.top().height >= s[i][j]) {
                combinedCount += S.top().count;
                S.pop();
            }

            llint currentAreaSum = combinedCount * static_cast<llint>(s[i][j]);
            if (S.top().value == a[i][j])
                currentAreaSum += S.top().areaSum;

            ans += currentAreaSum;
            S.push(RectangleInfo(combinedCount, a[i][j], s[i][j], currentAreaSum));
        }
    }

    cout << ans << "\n";

    return 0;
}
