#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canBuy(int k, vector<int>& prices, int a, int b) {

    vector<int> selected(prices.begin(), prices.begin() + k);
    sort(selected.begin(), selected.end());

    int discount = min(a, k);  
    long long total_cost = 0;

    for (int i = 0; i < k - discount; ++i) {
        total_cost += selected[i]; 
    }
    for (int i = k - discount; i < k; ++i) {
        total_cost += selected[i] / 2; 
    }

    return total_cost <= b; 
}

int main() {
    int n, b, a;
    cin >> n >> b >> a;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end());

    int low = 0, high = n, result = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canBuy(mid, prices, a, b)) {
            result = mid; 
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    cout << result << endl;
    return 0;
}