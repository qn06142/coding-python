#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        // If no chips, no diagonals will be occupied
        if (k == 0) {
            cout << 0 << endl;
            continue;
        }
        
        // Track occupied diagonals
        set<int> occupied_diagonals;

        // Simulate placing k chips
        int chip_count = 0;
        for (int i = 1; i <= n && chip_count < k; ++i) {
            for (int j = 1; j <= n && chip_count < k; ++j) {
                // Place a chip at (i, j)
                int diagonal = i + j;
                occupied_diagonals.insert(diagonal);
                ++chip_count;
            }
        }
        
        // Print the number of occupied diagonals
        cout << occupied_diagonals.size() << endl;
    }
    
    return 0;
}
