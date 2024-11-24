#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T, A, B;
    cin >> T >> A >> B;
    
    vector<bool> dp1(T + 1, false);
    vector<bool> dp2(T + 1, false);
    
    dp1[0] = true;
    
    for (int i = 0; i <= T; ++i) {
        if (dp1[i]) {
            if (i + A <= T) dp1[i + A] = true;
            if (i + B <= T) dp1[i + B] = true;
        }
    }
    
    for (int i = 0; i <= T; ++i) {
        if (dp1[i]) {
            int half_fullness = i / 2;
            dp2[half_fullness] = true;
        }
    }
    
    for (int i = 0; i <= T; ++i) {
        if (dp2[i]) {
            if (i + A <= T) dp2[i + A] = true;
            if (i + B <= T) dp2[i + B] = true;
        }
    }
    
    int max_fullness = 0;
    for (int i = 0; i <= T; ++i) {
        if (dp1[i] || dp2[i]) {
            max_fullness = max(max_fullness, i);
        }
    }
    
    cout << max_fullness << endl;
    
    return 0;
}
