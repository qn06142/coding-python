#include <iostream>
using namespace std;

const int MAXN = 1e6 + 5;
int piggy_banks[MAXN] = {0}, prefix[MAXN] = {0}, queries[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    cin >> N >> M;
    
    // Input and updating piggy_banks array
    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;
        piggy_banks[L]++;
        if (R + 1 <= N) {
            piggy_banks[R + 1]--;
        }
    }
    
    // Calculate the actual money in each piggy bank
    for (int i = 1; i <= N; i++) {
        piggy_banks[i] += piggy_banks[i - 1];
    }
    
    // Calculate the frequency of each money amount
    for (int i = 1; i <= N; i++) {
        if (piggy_banks[i] <= M) {
            prefix[piggy_banks[i]]++;
        }
    }
    
    // Calculate the number of piggy banks with at least x money
    for (int i = M - 1; i >= 0; i--) {
        prefix[i] += prefix[i + 1];
    }
    
    // Process queries
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        cout << prefix[x] << "\n";
    }

    return 0;
}
