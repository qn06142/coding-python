#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> fractions;

    
    for (int d = 1; d <= N; ++d) {
        for (int n = 0; n <= d; ++n) {
            if (gcd(n, d) == 1) { 
                fractions.push_back({n, d});
            }
        }
    }

    
    sort(fractions.begin(), fractions.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first * b.second < a.second * b.first;
    });

    
    auto result = fractions[K - 1];
    cout << result.first << "/" << result.second << endl;

    return 0;
}
