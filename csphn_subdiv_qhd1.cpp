#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> a;
int bestCount = -1;  // Lưu số phần tử nhiều nhất được chọn sao cho tổng % k = 0 (không tính trường hợp rỗng)

// Hàm backtracking: index là vị trí hiện tại, currentCount là số phần tử đã chọn,
// currentSum_mod là tổng (mod k) của các phần tử đã chọn.
void backtrack(int index, int currentCount, int currentSum_mod) {
    // Khi đã xét hết các phần tử:
    if(index == n) {
        // Kiểm tra nếu dãy con không rỗng và tổng chia hết cho k
        if(currentCount > 0 && currentSum_mod % k == 0) {
            bestCount = max(bestCount, currentCount);
        }
        return;
    }

    // Không chọn phần tử a[index]
    backtrack(index + 1, currentCount, currentSum_mod);

    // Chọn phần tử a[index]
    // Lưu ý: để tính đúng với số âm, ta chuyển về giá trị mod dương
    int modVal = ((a[index] % k) + k) % k;
    int newSum_mod = (currentSum_mod + modVal) % k;
    backtrack(index + 1, currentCount + 1, newSum_mod);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    backtrack(0, 0, 0);

    if(bestCount == -1)
        cout << -1;
    else
        cout << n - bestCount;

    return 0;
}
