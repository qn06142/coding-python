#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> circle;
    for (int i = 1; i <= n; ++i) {
        circle.push_back(i);
    }

    vector<int> josephus_order;
    int idx = 0;

    while (!circle.empty()) {
        idx = (idx + m - 1) % circle.size();
        josephus_order.push_back(circle[idx]);
        circle.erase(circle.begin() + idx);
    }

    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << josephus_order[i];
    }
    cout << endl;

    return 0;
}
