#include <bits/stdc++.h>
using namespace std;

#define MAXN 5001
#define MAXA 200000

int main() {
    int N;
    cin >> N;
    vector<int> A(N+1, 0);
    vector<long long> prefixSum(N+1, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        prefixSum[i] = prefixSum[i-1] + A[i];
    }
    int count2Sum = 0;

    for (int i = 1; i <= N; ++i) {
        map<long long, int> freqMap;
        for (int j = i; j <= N; ++j) {
            long long neededSum = prefixSum[j] + prefixSum[i-1];
            if (neededSum % 2 == 0 && freqMap.find(neededSum / 2) != freqMap.end()) {
                count2Sum += freqMap[neededSum / 2];
            }
            freqMap[prefixSum[j]]++;
        }
    }

    cout << count2Sum << endl;

    return 0;
}
