#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

struct Block {
    long long a, b, idx; 
};

int main() {
    long long V, N, M;
    cin >> V >> N >> M;

    vector<Block> blocks(N);
    for (int i = 0; i < N; ++i) {
        cin >> blocks[i].a >> blocks[i].b;
        blocks[i].idx = i + 1; 
    }

    sort(blocks.begin(), blocks.end(), [](const Block &x, const Block &y) {
        return x.a < y.a;
    });
    if (N == 0 || blocks[0].a > M) {
        if(V < M) {
            cout << -1;
            return 0;
        }
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N - 1; ++i) {
        if (blocks[i + 1].a - blocks[i].b - 1 >= M) {
            cout << 0 << endl;
            return 0;
        }
    }
    if (V - blocks[N - 1].b - 1 >= M) {
        cout << 0 << endl;
        return 0;
    }

    long long minSize = 1e18, bestIdx = -1;
    for (int i = 0; i < N; ++i) {
        long long size = blocks[i].b - blocks[i].a + 1;

        long long freeSpace = 0;
        if (i == 0) {
            freeSpace = blocks[i + 1].a - 1;
        } else if (i == N - 1) {
            freeSpace = V - blocks[i - 1].b - 1;
        } else {
            freeSpace = blocks[i + 1].a - blocks[i - 1].b - 1;
        }

        if (freeSpace >= M) {
            if (size < minSize || (size == minSize && blocks[i].a < blocks[bestIdx - 1].a)) {
                minSize = size;
                bestIdx = blocks[i].idx;
            }
        }
    }

    if (bestIdx == -1) {
        cout << -1 << endl; 
    } else {
        cout << bestIdx << endl; 
    }

    return 0;
}
