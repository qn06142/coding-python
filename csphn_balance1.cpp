#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> trees;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        trees[{x, y}]++;
    }
    int minTrees = INT_MAX;
    for (int a = 0; a <= m; a += 2) {
        for (int b = 0; b <= m; b += 2) {
            int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
            for (auto& tree : trees) {
                int x = tree.first.first;
                int y = tree.first.second;
                if (x < a && y < b) s1 += tree.second;
                else if (x < a && y > b) s2 += tree.second;
                else if (x > a && y > b) s3 += tree.second;
                else if (x > a && y < b) s4 += tree.second;
            }
            int maxTrees = max({s1, s2, s3, s4});
            minTrees = min(minTrees, maxTrees);
        }
    }
    cout << minTrees;
    return 0;
}
