#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = 0, j = 0;
    long long ans = 0;

    while (j < M) {

        while (i < N && A[i] < B[j]) ++i;

        if (i == N) {

            cout << -1 << endl;
            return 0;
        }

        ans += A[i];
        ++i; 
        ++j; 
    }

    cout << ans << endl;
    return 0;
}