#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> prev(N + 1, 0), next(N + 1, 0);

    // Khởi tạo mảng ban đầu
    for (int i = 1; i <= N; ++i) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    next[N] = 0; // Người cuối cùng không có ai sau

    // Xử lý K lần thay đổi
    for (int i = 0; i < K; ++i) {
        int A, B;
        cin >> A >> B;

        // Ngắt liên kết của A trong hàng
        if (prev[A] != 0) next[prev[A]] = next[A];
        if (next[A] != 0) prev[next[A]] = prev[A];

        // Chèn A trước B
        if (prev[B] != 0) next[prev[B]] = A;
        prev[A] = prev[B];
        next[A] = B;
        prev[B] = A;
    }

    // In kết quả
    for (int i = 1; i <= N; ++i) {
        cout << prev[i] << " " << next[i] << "\n";
    }

    return 0;
}
