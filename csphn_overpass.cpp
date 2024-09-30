#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> dpL(n + 1, INT_MAX); 
    vector<int> dpR(n + 1, INT_MAX); 

    dpL[0] = 0; 
    dpR[0] = INT_MAX; 

    for (int i = 1; i <= n; ++i) {
        char c = s[i - 1];

        if (c == 'L') {

            dpL[i] = dpL[i - 1]; 
            dpR[i] = dpL[i - 1] + 1; 
        } else if (c == 'R') {

            dpR[i] = dpR[i - 1]; 
            dpL[i] = dpR[i - 1] + 1; 
        } else if (c == 'B') {

            dpL[i] = min(dpL[i - 1], dpR[i - 1] + 1); 
            dpR[i] = min(dpR[i - 1], dpL[i - 1] + 1); 
        }
    }

    int result = min(dpL[n], dpR[n]);
    cout << result << endl;

    return 0;
}