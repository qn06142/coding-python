#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    unordered_set<int> album1;
    set<int> commonStamps;

    // Đọc các con tem của album thứ nhất
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        album1.insert(a[i]);
    }

    // Đọc các con tem của album thứ hai và tìm các con tem trùng nhau
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (album1.find(b[i]) != album1.end()) {
            commonStamps.insert(b[i]);
        }
    }

    // In kết quả
    if (commonStamps.empty()) {
        cout << 0 << endl;
    } else {
        cout << commonStamps.size() << endl;
        for (int stamp : commonStamps) {
            cout << stamp << " ";
        }
        cout << endl;
    }

    return 0;
}
