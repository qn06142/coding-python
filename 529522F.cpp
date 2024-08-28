#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, L, S;
    cin >> n >> L >> S;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<int> sums;
    int current_sum = 0;
    int max_sum = 0;

    // Duyệt qua mảng
    for (int i = 0; i < n; i++) {
        current_sum += a[i];

        // Nếu i >= L - 1, bắt đầu tính toán tổng cho cửa sổ có độ dài từ L đến S
        if (i >= L - 1) {
            sums.insert(current_sum); // Thêm tổng của cửa sổ hiện tại vào multiset
            if (i >= S) {
                current_sum -= a[i - S]; // Giảm tổng khi cửa sổ trượt qua khỏi S phần tử
                sums.erase(sums.find(current_sum)); // Xóa tổng cũ của cửa sổ khỏi multiset
            }
            max_sum = max(max_sum, *sums.rbegin()); // Cập nhật tổng lớn nhất
        }
    }

    cout << max_sum << endl;

    return 0;
}
