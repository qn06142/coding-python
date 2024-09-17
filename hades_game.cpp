#include <iostream>
#include <vector>
using namespace std;

long long compute_sum(const vector<long long>& X, long long P) {
    long long sum = 0;
    for (long long x : X) {
        sum += (x ^ P);  
    }
    return sum;
}

int main() {
    freopen("GAME.inp", "r", stdin);
    freopen("GAME.out", "w", stdout);
    int T;
    cin >> T;

    while (T--) {
        int N;
        long long M;
        cin >> N >> M;

        vector<long long> X(N);
        for (int i = 0; i < N; ++i) {
            cin >> X[i];
        }

        long long low = 0, high = (1LL << 50);  
        long long result = -1;

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long sum = compute_sum(X, mid);

            if (sum <= M) {
                result = mid;  
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }

        cout << result << endl;
    }

    return 0;
}