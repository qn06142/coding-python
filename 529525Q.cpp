#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Brick {
    int a, b, h;
};

bool compare(const Brick &b1, const Brick &b2) {
    if (b1.a != b2.a)
        return b1.a > b2.a;
    return b1.b > b2.b;
}

int main() {
    int N;
    cin >> N;
    vector<Brick> bricks(N);

    for (int i = 0; i < N; ++i) {
        cin >> bricks[i].a >> bricks[i].b >> bricks[i].h;
    }

    sort(bricks.begin(), bricks.end(), compare);

    vector<int> dp_count(N, 1); 
    vector<int> dp_height(N); 

    for (int i = 0; i < N; ++i) {
        dp_height[i] = bricks[i].h;
    }

    int max_count = 1;
    int max_height = dp_height[0];

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (bricks[i].a < bricks[j].a && bricks[i].b < bricks[j].b) {
                if (dp_count[i] < dp_count[j] + 1) {
                    dp_count[i] = dp_count[j] + 1;
                    dp_height[i] = dp_height[j] + bricks[i].h;
                } else if (dp_count[i] == dp_count[j] + 1) {
                    dp_height[i] = max(dp_height[i], dp_height[j] + bricks[i].h);
                }
            }
        }
        max_count = max(max_count, dp_count[i]);
        max_height = max(max_height, dp_height[i]);
    }

    cout << max_count << " " << max_height << endl;

    return 0;
}