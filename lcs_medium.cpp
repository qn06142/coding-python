#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

const int INF = INT_MAX;

void computeNext(const string &y, vector<vector<int>> &Next) {
    int n = y.size();
    Next.assign(26, vector<int>(n + 2, n + 1)); 

    for (int c = 0; c < 26; ++c) {
        Next[c][n + 1] = n + 1; 
    }

    for (int i = n; i >= 1; --i) {
        for (int c = 0; c < 26; ++c) {
            Next[c][i] = Next[c][i + 1]; 
        }
        Next[y[i - 1] - 'A'][i] = i; 
    }
}

int computeLCS(const string &x, const string &y) {
    int m = x.size(), n = y.size();
    vector<int> prev(m + 1, n + 1), curr(m + 1, n + 1); 
    vector<vector<int>> Next;

    computeNext(y, Next);

    prev[0] = 0; 

    for (int i = 1; i <= m; ++i) {
        curr[0] = 0; 
        for (int k = 1; k <= m; ++k) { 
            curr[k] = prev[k]; 
            int j_prev = prev[k - 1];
            if (j_prev <= n) { 
                int j = Next[x[i - 1] - 'A'][j_prev + 1];
                if (j <= n) {
                    curr[k] = min(curr[k], j);
                }
            }
        }
        swap(prev, curr); 
    }

    int maxLCS = 0;
    for (int k = 0; k <= m; ++k) { 
        if (prev[k] <= n) {
            maxLCS = k;
        }
    }

    return maxLCS;
}

int main() {
    string x, y;
    cin >> x >> y;
    int lcsLength = computeLCS(x, y);
    cout << lcsLength << endl;

    return 0;
}