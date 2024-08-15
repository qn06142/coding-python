#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> pilots(N);
    vector<pair<int, int>> diff(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> pilots[i].first >> pilots[i].second;
        diff[i] = {pilots[i].first - pilots[i].second, i};
    }
    
    // Sắp xếp các phi công dựa trên sự chênh lệch giữa lương lái chính và lương lái phụ
    sort(diff.begin(), diff.end());
    
    int total_cost = 0;
    
    // Chọn N/2 phi công với sự chênh lệch nhỏ nhất làm lái chính
    for (int i = 0; i < N / 2; ++i) {
        total_cost += pilots[diff[i].second].first;
    }
    
    // Chọn N/2 phi công còn lại làm lái phụ
    for (int i = N / 2; i < N; ++i) {
        total_cost += pilots[diff[i].second].second;
    }
    
    cout << total_cost << endl;
    return 0;
}
