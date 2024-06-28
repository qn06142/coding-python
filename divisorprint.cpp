#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_X = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    // Tiền xử lý ước số cho tất cả các số từ 1 đến MAX_X
    vector<vector<int>> divisors(MAX_X + 1);

    for (int i = 1; i <= MAX_X; ++i) {
        for (int j = i; j <= MAX_X; j += i) {
            divisors[j].push_back(i);
        }
    }

    // Xử lý các truy vấn và xuất kết quả
    for (int i = 0; i < q; ++i) {
        int xi = queries[i];
        for (size_t j = 0; j < divisors[xi].size(); ++j) {
            if (j > 0) cout << " ";
            cout << divisors[xi][j];
        }
        cout << "\n";
    }

    return 0;
}
