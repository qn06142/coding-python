#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

int binarySearch(const vector<int>& h, int val, int nRobots) {
    int low = 0, high = nRobots;
    while (low < high) {
        int mid = (low + high) / 2;
        if (h[mid] > val) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    vector<int> h(n);

    int nRobots = 0;  

    for (int i = 0; i < n; ++i) {
        int y = points[i].y;
        int pos = binarySearch(h, y, nRobots);

        h[pos] = y;

        if (pos == nRobots) {
            nRobots++;
        }
    }

    cout << nRobots << endl;

    return 0;
}