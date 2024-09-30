#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Vector để chứa giá trị nhỏ nhất của từng đoạn K
    vector<int> mins;
    deque<int> dq;

    // Duyệt qua mảng và tìm giá trị nhỏ nhất của mỗi đoạn K
    for (int i = 0; i < N; i++) {
        // Loại bỏ các phần tử không nằm trong khoảng K
        if (!dq.empty() && dq.front() <= i - K) {
            dq.pop_front();
        }
        
        // Loại bỏ các phần tử lớn hơn phần tử hiện tại (vì chúng không cần thiết)
        while (!dq.empty() && A[dq.back()] >= A[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Khi i >= K - 1, nghĩa là đoạn đã đủ K phần tử, lấy phần tử nhỏ nhất
        if (i >= K - 1) {
            mins.push_back(A[dq.front()]);
        }
    }

    // Sắp xếp danh sách các giá trị nhỏ nhất của các đoạn
    sort(mins.begin(), mins.end());

    // Chọn Q giá trị nhỏ nhất và tính chênh lệch
    int result = mins[Q-1] - mins[0];
    cout << result << endl;

    return 0;
}
