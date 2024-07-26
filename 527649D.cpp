#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm để lấy cặp số thứ V trong danh sách đã sắp xếp
pair<int, int> findPair(int N, int K, int V) {
    vector<pair<int, int>> pairs;
    
    // Tạo tất cả các cặp số (a, b) thỏa mãn 1 ≤ a, b ≤ N
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            pairs.emplace_back(a, b);
        }
    }

    // Sắp xếp các cặp số theo giá trị không giảm, nếu giá trị giống nhau thì sắp xếp theo a
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        int sum1 = p1.first + p1.second;
        int sum2 = p2.first + p2.second;
        if (sum1 != sum2) {
            return sum1 < sum2;
        }
        return p1.first < p2.first;
    });

    // Lấy cặp số thứ V (lưu ý V là 1-based index, nên chúng ta cần trừ 1 để truy cập trong vector)
    if (V >= 1 && V <= pairs.size()) {
        return pairs[V - 1];
    } else {
        return {-1, -1}; // Trả về cặp số không hợp lệ nếu V ngoài phạm vi
    }
}

int main() {
    int N, K, V;
    cin >> N >> K >> V;

    pair<int, int> result = findPair(N, K, V);
    if (result.first != -1) {
        cout << result.first << " " << result.second << endl;
    } else {
        cout << "Invalid V" << endl;
    }

    return 0;
}
