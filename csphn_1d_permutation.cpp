#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n), x;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    for (int i = n; i >= 1; i--) {
        x.insert(x.begin() + t[i-1], i);
    }
    
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    return 0;
}
