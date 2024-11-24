#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> books(k); // Lưu vị trí sách, pair<kệ, độ cao>

    for (int i = 0; i < k; ++i) {
        cin >> books[i].first >> books[i].second;
    }

    // Sắp xếp sách theo kệ và độ cao
    sort(books.begin(), books.end());

    // DP mảng, khởi tạo với giá trị vô cùng lớn
    vector<int> dp(n + 1, INF);
    dp[0] = 0; // Khởi tạo dp[0] bằng 0, tức là chưa leo lên kệ nào

    // Tạo một mảng lưu độ cao lớn nhất trên mỗi kệ
    vector<int> max_height(n + 1, 0);

    // Lưu độ cao cao nhất của các kệ
    for (int i = 0; i < k; ++i) {
        int shelf = books[i].first;
        int height = books[i].second;
        max_height[shelf] = max(max_height[shelf], height);
    }

    // Duyệt qua từng kệ để tính tổng độ cao cần leo
    for (int i = 1; i <= n; ++i) {
        if (max_height[i] > 0) {
            // Lựa chọn leo kệ hiện tại, cộng với độ cao của kệ này
            dp[i] = min(dp[i], dp[i - 1] + max_height[i]);

            // Nếu có kệ bên cạnh (trái) có sách
            if (i > 1 && max_height[i - 1] > 0) {
                dp[i] = min(dp[i], dp[i - 2] + max(max_height[i], max_height[i - 1]));
            }
        }
    }

    // Nếu giá trị dp[n] vẫn là INF, nghĩa là không có cách nào hợp lệ
    if (dp[n] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dp[n] << "\n";
    }

    return 0;
}
