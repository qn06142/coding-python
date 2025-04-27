#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x < 0) {  
            long long t = -x; 
            if (t > ans)
                ans = t;
        } else {      
            long long t = k - x;
            if (t > ans)
                ans = t;
        }
    }

    cout << ans;
    return 0;
}