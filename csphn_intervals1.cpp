#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> intervals(n);
    
    // Đọc dữ liệu
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    int count = 0;
    
    // Duyệt tất cả các cặp khoảng
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int L1 = intervals[i].first, R1 = intervals[i].second;
            int L2 = intervals[j].first, R2 = intervals[j].second;
            
            // Kiểm tra nếu hai khoảng giao nhau
            if (max(L1, L2) <= min(R1, R2)) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}
