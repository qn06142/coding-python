#include <bits/stdc++.h>
using namespace std;

vector<int> cmpx, cmpy;

// Compression functions
int compressx(int i) {
    return lower_bound(cmpx.begin(), cmpx.end(), i) - cmpx.begin() + 1;
}
int compressy(int i) {
    return lower_bound(cmpy.begin(), cmpy.end(), i) - cmpy.begin() + 1;
}

// Fisherman struct
struct fisher {
    int x1, y1, x2, y2;
    fisher(int pos, int l) {
        x1 = compressx(pos - l);
        y1 = compressy(-l);
        x2 = compressx(pos + l);
        y2 = compressy(l);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, l;
    cin >> n >> m >> l;

    vector<pair<int, int>> fishes(n + 1);
    vector<int> fisherman_positions(m);

    // Reading fish positions
    for (int i = 1; i <= n; i++) {
        cin >> fishes[i].first >> fishes[i].second;
        cmpx.push_back(fishes[i].first);
        cmpy.push_back(fishes[i].second);
    }

    // Reading fisherman positions
    for (int i = 0; i < m; i++) {
        cin >> fisherman_positions[i];
        cmpx.push_back(fisherman_positions[i] - l);
        cmpx.push_back(fisherman_positions[i] + l);
        cmpy.push_back(-l);
        cmpy.push_back(l);
    }

    // Coordinate compression
    sort(cmpx.begin(), cmpx.end());
    cmpx.erase(unique(cmpx.begin(), cmpx.end()), cmpx.end());
    sort(cmpy.begin(), cmpy.end());
    cmpy.erase(unique(cmpy.begin(), cmpy.end()), cmpy.end());

    // Create prefix sum grid
    int maxx = cmpx.size(), maxy = cmpy.size();
    vector<vector<int>> pref(maxx + 1, vector<int>(maxy + 1, 0));

    // Compress fish positions and update grid
    for (int i = 1; i <= n; i++) {
        int cx = compressx(fishes[i].first);
        int cy = compressy(fishes[i].second);
        pref[cx][cy]++;
    }

    // Build prefix sum
    for (int i = 1; i <= maxx; i++) {
        for (int j = 1; j <= maxy; j++) {
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    // Process fishermen and query results
    vector<fisher> fishers;
    for (int i = 0; i < m; i++) {
        fishers.emplace_back(fisherman_positions[i], l);
    }

    for (fisher f : fishers) {
        // Bounds check
        int x1 = max(1, f.x1), y1 = max(1, f.y1);
        int x2 = min(maxx, f.x2), y2 = min(maxy, f.y2);

        // Prefix sum query
        int ans = pref[x2][y2] 
                - (x1 > 1 ? pref[x1 - 1][y2] : 0) 
                - (y1 > 1 ? pref[x2][y1 - 1] : 0) 
                + (x1 > 1 && y1 > 1 ? pref[x1 - 1][y1 - 1] : 0);
        cout << ans << '\n';
    }

    return 0;
}
