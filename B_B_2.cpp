#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t; // Số lượng test cases
    
    while (t--) {
        int n;
        cin >> n; // Số vòng chơi
        
        vector<long long> a(n);
        long long current_score = 0, min_score = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            current_score += a[i]; // Cộng dồn điểm
            min_score = min(min_score, current_score); // Theo dõi điểm thấp nhất
        }
        
        // min_score là giá trị nhỏ nhất mà tổng điểm đạt được, đó chính là giá trị k tốt nhất
        cout << -min_score << "\n";
    }
    
    return 0;
}
