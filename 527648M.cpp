#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool find(int q, int l, int r, const vector<int>& f) {
    while (l <= r) {
        int x = (l + r) / 2;
        if (q == f[x]) {
            return true;
        }
        if (q < f[x]) {
            r = x - 1;
        } else {
            l = x + 1;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> f(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        int value;
        cin >> value;
        f[i] = f[i - 1] + value;
    }
    
    for (int len = n; len >= 2; --len) {
        for (int l = 1; l <= n - len + 1; ++l) {
            if ((f[l - 1] + f[l + len - 1]) % 2 == 0) {
                if (find((f[l - 1] + f[l + len - 1]) / 2, l, l + len - 1, f)) {
                    cout << len << endl;
                    return 0;
                }
            }
        }
    }
    
    cout << 0 << endl;
    return 0;
}
