#include <bits/stdc++.h>
using namespace std;

// Define a structure for the bricks
struct Brick {
    int length, width, height;
};

// Comparator function to sort bricks
bool cmp(const Brick &a, const Brick &b) {
    if (a.length == b.length) return a.width > b.width;
    return a.length > b.length;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<Brick> bricks(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> bricks[i].length >> bricks[i].width >> bricks[i].height;
    }
    
    // Sort the bricks
    sort(bricks.begin(), bricks.end(), cmp);
    
    // DP arrays
    vector<int> dp_height(n);
    vector<int> dp_count(n);
    
    int maxHeight = 0;
    int maxBricks = 0;
    
    for (int i = 0; i < n; ++i) {
        dp_height[i] = bricks[i].height;  // Base case, the height with only this brick
        dp_count[i] = 1;  // Base case, at least one brick is there
        
        for (int j = 0; j < i; ++j) {
            if (bricks[j].length > bricks[i].length && bricks[j].width > bricks[i].width) {
                if (dp_height[j] + bricks[i].height > dp_height[i]) {
                    dp_height[i] = dp_height[j] + bricks[i].height;
                    dp_count[i] = dp_count[j] + 1;
                } else if (dp_height[j] + bricks[i].height == dp_height[i]) {
                    dp_count[i] = max(dp_count[i], dp_count[j] + 1);
                }
            }
        }
        
        maxHeight = max(maxHeight, dp_height[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (dp_height[i] == maxHeight) {
            maxBricks = max(maxBricks, dp_count[i]);
        }
    }
    
    cout << maxBricks << " " << maxHeight << endl;
    
    return 0;
}
