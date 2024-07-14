#include <iostream>
using namespace std;

int maxGames(int k, int n, int a, int b) {

    if (k > a) {
        return n;
    }

    int maxGames = (k - b) / (a - b);

    if ((k - b) % (a - b) != 0) {
        return -1; 
    }
    return maxGames;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, n, a, b;
        cin >> k >> n >> a >> b;
        int result = maxGames(k, n, a, b);
        if (result == -1) {
            cout << "bruh\n";
        } else {
            cout << result << "\n";
        }
    }
    return 0;
}