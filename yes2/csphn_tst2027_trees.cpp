#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int countTrees(vector<pair<int, int>>& points) {
    int n = points.size();
    int result = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> p1 = points[i];
        pair<int, int> p2 = points[(i + 1) % n];
        result += gcd(abs(p2.first - p1.first), abs(p2.second - p1.second));
    }
    return result;
}

int main() {
    int n;

    cin >> n;
    vector<pair<int, int>> points(n);

    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    cout << countTrees(points);
    return 0;
}
