#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int a[MAXN][MAXN];
int rowMax[MAXN][MAXN];
int rowMin[MAXN][MAXN];
int colMax[MAXN][MAXN];
int colMin[MAXN][MAXN];

void slidingMax(int* arr, int n, int k, int* result) {
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result[i - k + 1] = arr[dq.front()];
    }
}

void slidingMin(int* arr, int n, int k, int* result) {
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result[i - k + 1] = arr[dq.front()];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, k;
    cin >> N >> M >> k;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> a[i][j];

    for (int i = 0; i < N; ++i) {
        slidingMax(a[i], M, k, rowMax[i]);
        slidingMin(a[i], M, k, rowMin[i]);
    }

    for (int j = 0; j <= M - k; ++j) {
        int tempMax[MAXN];
        int tempMin[MAXN];
        for (int i = 0; i < N; ++i) {
            tempMax[i] = rowMax[i][j];
            tempMin[i] = rowMin[i][j];
        }
        slidingMax(tempMax, N, k, colMax[j]);
        slidingMin(tempMin, N, k, colMin[j]);
    }

    int result = 1e9;
    for (int i = 0; i <= N - k; ++i) {
        for (int j = 0; j <= M - k; ++j) {
            result = min(result, colMax[j][i] - colMin[j][i]);
        }
    }

    cout << result << "\n";
    return 0;
}