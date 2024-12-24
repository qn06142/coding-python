#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 300;
long long dp[MAXN + 1][MAXN + 1];

void precompute(int N) {
    for (int i = 0; i <= N; ++i) {
        dp[i][0] = 1; 
    }
    for (int i = 1; i <= N; ++i) {
        for (int k = 1; k <= i; ++k) {
            dp[i][k] = dp[i-1][k] + dp[i-1][k-1];
        }
    }
}

vector<int> findCombination(int N, int K, long long S) {
    vector<int> result;
    int current = 1;
    for (int i = 1; i <= K; ++i) {
        for (int num = current; num <= N; ++num) {
            if (dp[N - num][K - i] >= S) {
                result.push_back(num);
                current = num + 1;
                break;
            } else {
                S -= dp[N - num][K - i];
            }
        }
    }
    return result;
}

long long findRank(int N, int K, const vector<int>& B) {
    long long rank = 1;
    int current = 1;
    for (int i = 0; i < K; ++i) {
        for (int num = current; num < B[i]; ++num) {
            rank += dp[N - num][K - i - 1];
        }
        current = B[i] + 1;
    }
    return rank;
}

int main() {
    int N, K;
    cin >> N >> K;

    precompute(N);

    long long S;
    cin >> S;
    vector<int> B(K);
    for (int i = 0; i < K; ++i) {
        cin >> B[i];
    }

    vector<int> combination = findCombination(N, K, S);
    for (size_t i = 0; i < combination.size(); ++i) {
        if (i > 0) cout << " ";
        cout << combination[i];
    }
    cout << endl;

    cout << findRank(N, K, B) << endl;

    return 0;
}