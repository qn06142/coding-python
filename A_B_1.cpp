#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> weights(2 * n);
    
    for(int i = 0; i < 2 * n; ++i) {
        cin >> weights[i];
    }
    
    sort(weights.begin(), weights.end());
    
    int min_instability = INT_MAX;
    
    for(int i = 0; i < 2 * n; ++i) {
        for(int j = i + 1; j < 2 * n; ++j) {
            vector<int> remaining_weights;
            
            for(int k = 0; k < 2 * n; ++k) {
                if (k != i && k != j) {
                    remaining_weights.push_back(weights[k]);
                }
            }
            
            int current_instability = 0;
            
            for(int k = 0; k < remaining_weights.size(); k += 2) {
                current_instability += abs(remaining_weights[k] - remaining_weights[k + 1]);
            }
            
            min_instability = min(min_instability, current_instability);
        }
    }
    
    cout << min_instability << endl;
    
    return 0;
}
