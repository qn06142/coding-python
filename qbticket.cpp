#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main() {
    long long L1, L2, L3, C1, C2, C3;
    cin >> L1 >> L2 >> L3 >> C1 >> C2 >> C3;

    int N;
    cin >> N;

    int s, t;
    cin >> s >> t;

    if (s > t) swap(s, t);

    vector<long long> dist(N);
    for (int i = 1; i < N; ++i) {
        cin >> dist[i];
    }
    
    vector<long long> cost(N, INF);
    cost[s-1] = 0;

    for (int i = s; i < t; ++i) {
        for (int j = i + 1; j <= t; ++j) {
            long long d = dist[j-1] - dist[i-1];
            if (d <= L1) {
                cost[j-1] = min(cost[j-1], cost[i-1] + C1);
            } else if (d <= L2) {
                cost[j-1] = min(cost[j-1], cost[i-1] + C2);
            } else if (d <= L3) {
                cost[j-1] = min(cost[j-1], cost[i-1] + C3);
            }
        }
    }
    
    cout << cost[t-1] << endl;

    return 0;
}
