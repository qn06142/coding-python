#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; 

    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] %= MOD;
    }

    int m;
    cin >> m; 

    if(m == 0) {
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
        return 0;
    }

    for (int day = 0; day < m; day++){
        for (int i = 1; i < n; i++){
            a[i] = (a[i] + a[i-1]) % MOD;
        }
    }

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}