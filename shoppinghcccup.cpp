#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxItems(int n, int c, vector<int>& prices) {
    // Sắp xếp giá các món ăn từ thấp đến cao
    sort(prices.begin(), prices.end());
    
    // Khởi tạo biến đếm số lượng món ăn có thể mua
    int count = 0;
    
    // Duyệt qua từng món ăn
    for (int price : prices) {
        if (c >= price) {
            c -= price;
            count++;
        } else {
            break;
        }
    }
    
    return count;
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> prices(n);
    
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    cout << maxItems(n, c, prices) << endl;
    
    return 0;
}
