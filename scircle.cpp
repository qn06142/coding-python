#include <iostream>
#include <list>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    list<int> circle;

    for (int i = 1; i <= n; ++i) {
        circle.push_back(i);
    }

    list<int>::iterator pos[100005];
    int index = 1;
    for (auto it = circle.begin(); it != circle.end(); ++it) {
        pos[index++] = it;
    }

    for (int k = 0; k < m; ++k) {
        int i, j;
        cin >> i >> j;

        auto it_i = pos[i];
        circle.erase(it_i);

        auto it_j = pos[j];
        pos[i] = circle.insert(it_j, i);
    }

    auto start = pos[1];
    for (auto it = start; it != circle.end(); ++it) {
        cout << *it << " ";
    }
    for (auto it = circle.begin(); it != start; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}