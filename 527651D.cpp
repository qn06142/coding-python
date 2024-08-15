#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_a = *max_element(a.begin(), a.end());
    vector<int> freq(max_a + 1, 0);
    
    // Tính tần số của các phần tử trong mảng
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    int best_gcd = 1;
    // Xét các GCD từ 1 đến max_a
    for (int g = 1; g <= max_a; g++) {
        int count = 0;
        // Kiểm tra với bội số của g
        for (int multiple = g; multiple <= max_a; multiple += g) {
            // Số lượng phần tử có giá trị thuộc [multiple-k, multiple]
            count += freq[multiple];
        }
        // Nếu số lượng phần tử >= n thì g là một ứng cử viên tốt cho GCD
        if (count == n) {
            best_gcd = g;
        }
    }

    cout << best_gcd << endl;
    return 0;
}
