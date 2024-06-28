#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100005; // Số lượng hộp kẹo tối đa
const int MAX_M = 100005; // Số lượng bạn tối đa

int a[MAX_N]; // Mảng chứa số lượng kẹo trong mỗi hộp
int b[MAX_M]; // Mảng chứa độ tế nhị của mỗi bạn
int result[MAX_M]; // Mảng chứa kết quả số kẹo mà mỗi bạn đã ăn
int fenwick_tree[MAX_N]; // Fenwick Tree để quản lý số lượng kẹo

// Cập nhật Fenwick Tree
void update(int index, int delta, int n) {
    while (index <= n) {
        fenwick_tree[index] += delta;
        index += index & -index;
    }
}

// Lấy tổng số kẹo từ hộp 1 đến hộp index
int query(int index) {
    int sum = 0;
    while (index > 0) {
        sum += fenwick_tree[index];
        index -= index & -index;
    }
    return sum;
}

// Tìm vị trí đầu tiên mà tổng số kẹo >= x
int find_first_ge(int x, int n) {
    int low = 1, high = n, pos = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (query(mid) >= x) {
            pos = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return pos;
}

int main() {
    int n, m;
    // Đọc số lượng hộp kẹo
    cin >> n;
    vector<pair<int, int>> candy(n);
    // Đọc số lượng kẹo trong mỗi hộp và lưu kèm theo chỉ số ban đầu
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        candy[i] = {a[i], i + 1}; // Lưu giá trị kẹo và chỉ số 1-based
    }

    // Sắp xếp danh sách candy theo số lượng kẹo
    sort(candy.begin(), candy.end());

    // Khởi tạo Fenwick Tree
    for (int i = 0; i < n; ++i) {
        update(candy[i].second, candy[i].first, n);
    }

    // Đọc số lượng bạn tới dự tiệc
    cin >> m;
    // Đọc độ tế nhị của mỗi bạn
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    // Xử lý từng bạn một
    for (int j = 0; j < m; ++j) {
        int bi = b[j];
        int count = 0;
        while (true) {
            int index = find_first_ge(bi, n);
            if (index == -1) break; // Không còn hộp nào phù hợp
            int delta = query(index) - query(index - 1);
            if (delta >= bi) {
                count++;
                update(index, -1, n); // Giảm một viên kẹo từ hộp này
            } else {
                break;
            }
        }
        result[j] = count;
    }

    // Xuất kết quả
    for (int j = 0; j < m; ++j) {
        cout << result[j] << endl;
    }

    return 0;
}
