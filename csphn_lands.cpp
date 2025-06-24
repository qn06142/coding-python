#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MAX_N = 50;
int n, a[MAX_N + 1][MAX_N + 1], pref[MAX_N + 1][MAX_N + 1];

void compute_prefix_sum() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = a[i][j] 
                       + (i > 1 ? pref[i-1][j] : 0) 
                       + (j > 1 ? pref[i][j-1] : 0) 
                       - (i > 1 && j > 1 ? pref[i-1][j-1] : 0);
        }
    }
}

int region_sum(int x1, int y1, int x2, int y2) {
    return pref[x2][y2] 
         - (y1 > 1 ? pref[x2][y1 - 1] : 0)
         - (x1 > 1 ? pref[x1 - 1][y2] : 0)
         + (x1 > 1 && y1 > 1 ? pref[x1 - 1][y1 - 1] : 0);
}
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
int count_divisions() {
    int total_ways = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            gp_hash_table<int, int> cnt;
            for (int x = 1; x <= i; x++) {
                for (int y = 1; y <= j; y++) {
                    int s = region_sum(x, y, i, j);
                    cnt[s]++;
                }
            }
            for (int u = i + 1; u <= n; u++) {
                for (int v = j + 1; v <= n; v++) {
                    int s1 = region_sum(i + 1, j + 1, u, v);
                    total_ways += cnt[s1];
                }
            }
            cnt.clear();
            for (int x = i; x <= n; x++) {
                for (int y = 1; y <= j; y++) {
                    int s = region_sum(i, y, x, j);
                    cnt[s]++;
                }
            }
            for (int u = 1; u < i; u++) {
                for (int v = j + 1; v <= n; v++) {
                    int s1 = region_sum(u, j + 1, i - 1, v);
                    total_ways += cnt[s1];
                }
            }

        }
    }

    return total_ways;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    compute_prefix_sum();
    cout << count_divisions() << endl;

    return 0;
}
