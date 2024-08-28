#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> islands(n);

    for (int i = 0; i < n; ++i) {
        int a, x;
        cin >> a >> x;
        islands[i] = {x, a};
    }

    sort(islands.begin(), islands.end());

    int ans = 0, curr = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        curr += islands[right].second;

        while (islands[right].first - islands[left].first > 2 * k) {
            curr -= islands[left].second;
            left++;
        }

        ans = max(ans, curr);
    }

    cout << ans << "\n";
    return 0;
}