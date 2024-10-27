#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int nm = n * m;
    vector<bool> nnig(nm + 1, false);
    int top = 0, b = n - 1, l = 0, r = m - 1;
    int num = 1;
    vector<vector<int>> a(n, vector<int>(m));

    while (top <= b && l <= r) {
        for (int i = l; i <= r; ++i) {
            a[top][i] = num++;
        }
        top++;
        for (int i = top; i <= b; ++i) {
            a[i][r] = num++;
        }
        r--;
        if (top <= b) {
            for (int i = r; i >= l; --i) {
                a[b][i] = num++;
            }
            b--;
        }
        if (l <= r) {
            for (int i = b; i >= top; --i) {
                a[i][l] = num++;
            }
            l++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c;
            cin >> c;
            nnig[a[i][j]] = (c == 0);
        }
    }

    vector<int> dist(nm + 1, INT_MAX);
    deque<int> dq;

    if (nnig[1]) {
        dist[1] = 0;
        dq.push_back(1);
    }
    for (int i = 2; i <= nm; ++i) {
        if (!nnig[i]) continue;
        while (!dq.empty() && dq.front() < i - k) {
            dq.pop_front();
        }
        if (dq.empty()) continue;
        dist[i] = dist[dq.front()] + 1;
        while (!dq.empty() && dist[i] <= dist[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    int P = (dist[nm] == INT_MAX) ? -1 : dist[nm];
    vector<int> pw(nm + 2, 0);
    for (int i = 1; i <= nm; ++i) {
        pw[i] = pw[i - 1] + nnig[i];
    }

    int Q = 0;
    for (int i = 1; i <= nm; ++i) {
        if (!nnig[i]) continue;
        int l = i + 1;
        int r = min(i + k, nm);
        int Fi = pw[r] - pw[i];
        Q = max(Q, Fi);
    }

    cout << P << " " << Q << endl;
}
