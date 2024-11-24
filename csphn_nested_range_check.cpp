#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int left, right, index;
};

bool compareSegments(const Segment &a, const Segment &b) {
    if (a.left == b.left) return a.right > b.right;
    return a.left < b.left;
}

int main() {
    int n;
    cin >> n;

    vector<Segment> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].left >> segments[i].right;
        segments[i].index = i;
    }

    sort(segments.begin(), segments.end(), compareSegments);

    vector<int> is_contained(n, 0);
    vector<int> contains(n, 0);

    int max_right = -1;
    for (int i = 0; i < n; i++) {
        if (segments[i].right <= max_right) {
            is_contained[segments[i].index] = 1; 
        }
        max_right = max(max_right, segments[i].right);
    }

    int min_right = 1e9 + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (segments[i].right >= min_right) {
            contains[segments[i].index] = 1; 
        }
        min_right = min(min_right, segments[i].right);
    }
    for (int i = 0; i < n; i++) {
        cout << contains[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << is_contained[i] << " ";
    }
    cout << endl;

    return 0;
}