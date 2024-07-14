#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    #define int long long
    int n;
    cin >> n;
    vector<long long> coins(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin() + 1, coins.end());
    int s = 0;
    int c = 0;
    for(int i = 1; i <= n; i++) {
        if(coins[i] > s) {
            s += coins[i];
            c++;
        } else {
            s -= coins[i - 1];
            s += coins[i];

        }
    }
    cout << c << ' ' << s << endl;
}
