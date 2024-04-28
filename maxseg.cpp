#include <iostream>
#include <vector>
#include <limits>
using namespace std;
int a[(int) 1e5 + 5];
int calc() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long best = numeric_limits<int>::min();
    long long bestend = 0;
    for(int i = 0; i < n; i++) {
        bestend += a[i];
        if(best < bestend) {
            best = bestend;
        }
        if(bestend < 0) {
            bestend = 0;
        }
    }
    return best;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cout << calc() << endl;
    }
}