#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long D[11];  

    D[0] = 1;  
    D[1] = 0;  

    for (int i = 2; i <= n; i++) {
        D[i] = (i - 1) * (D[i - 1] + D[i - 2]);
    }

    cout << D[n] << endl;

    return 0;
}