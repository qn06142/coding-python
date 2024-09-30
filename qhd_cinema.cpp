#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[1005][1005];

int maxSatisfaction(int guest, int currentSatisfaction, vector<bool>& used) {
    if (guest > n) {
        return currentSatisfaction;
    }
    
    int maxSatis = 0;
    for (int seat = 1; seat <= n; seat++) {
        if (!used[seat]) {
            used[seat] = true;
            maxSatis = max(maxSatis, maxSatisfaction(guest + 1, currentSatisfaction + a[guest][seat], used));
            used[seat] = false;
        }
    }
    return maxSatis;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    vector<bool> used(n + 1, false);
    int result = maxSatisfaction(1, 0, used);
    cout << result << endl;

    return 0;
}