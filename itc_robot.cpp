#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
using namespace std;

const int MAX_N = 1001;
const int MAX_M = 1001;

int A[MAX_N][MAX_M];
unordered_map<int, int> dp[MAX_N][MAX_M];

int main() {
    ifstream infile("ROBOT.INP");
    ofstream outfile("ROBOT.OUT");

    int N, M, Q, K;
    infile >> N >> M >> Q >> K;
    vector<int> queries(Q);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            infile >> A[i][j];
        }
    }

    for (int i = 0; i < Q; ++i) {
        infile >> queries[i];
    }

    // Initialize the starting position
    dp[1][1][A[1][1] % K] = 1;

    // Fill the DP table
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (i == 1 && j == 1) continue;

            unordered_map<int, int> &current_map = dp[i][j];

            if (j > 1) {
                for (const auto &entry : dp[i][j-1]) {
                    current_map[entry.first] = max(current_map[entry.first], entry.second);
                }
            }
            if (i > 1) {
                for (const auto &entry : dp[i-1][j]) {
                    current_map[entry.first] = max(current_map[entry.first], entry.second);
                }
            }
            if (i > 1 && j > 1) {
                for (const auto &entry : dp[i-1][j-1]) {
                    current_map[entry.first] = max(current_map[entry.first], entry.second);
                }
            }

            int mod_val = A[i][j] % K;
            current_map[mod_val]++;
        }
    }

    // Output the results for each query
    for (int q = 0; q < Q; ++q) {
        int X = queries[q];
        outfile << dp[N][M][X] << endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
