#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxValue(vector<int> a) {

    if (a.size() == 1) {
        return a[0];
    }

    int max_result = 0;

    for (int i = 0; i < a.size(); ++i) {
        for (int j = i + 1; j < a.size(); ++j) {

            int average = (a[i] + a[j]) / 2;

            vector<int> new_array;
            for (int k = 0; k < a.size(); ++k) {
                if (k != i && k != j) {
                    new_array.push_back(a[k]);
                }
            }
            new_array.push_back(average); 

            max_result = max(max_result, maxValue(new_array));
        }
    }

    return max_result;
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n; 
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; 
        }

        cout << maxValue(a) << endl;
    }
    return 0;
}