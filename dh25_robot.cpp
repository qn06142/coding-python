#include <bits/stdc++.h>
using namespace std;

static const int MAX_M = 200;

static const int di[4] = {-1,+1, 0, 0};
static const int dj[4] = { 0, 0,-1,+1};
static const char dc[4] = {'U','D','L','R'};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        cin >> grid[i][j];

    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    if (grid[0][0] == 0) {
      deque<pair<int,int>> dq;
      dist[0][0] = 0;
      dq.emplace_back(0,0);
      while (!dq.empty()) {
        auto [i,j] = dq.front(); dq.pop_front();
        for (int d = 0; d < 4; d++) {
          int ni = i + di[d], nj = j + dj[d];
          if (ni>=0 && ni<n && nj>=0 && nj<m
           && grid[ni][nj]==0
           && dist[ni][nj] == INF)
          {
            dist[ni][nj] = dist[i][j] + 1;
            dq.emplace_back(ni,nj);
          }
        }
      }
    }

    int max_d = 0;
    vector<pair<int,int>> init;
    init.reserve(k);
    for (int t = 0; t < k; t++) {
      int si, sj;
      cin >> si >> sj;
      if (dist[si][sj] < INF) {
        init.emplace_back(si,sj);
        max_d = max(max_d, dist[si][sj]);
      }
    }

    vector< bitset<MAX_M> > grid_free(n), alive(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0)
          grid_free[i].set(j);
      }
    }
    for (auto &p : init)
      alive[p.first].set(p.second);

    vector< vector< bitset<MAX_M> > > layer_bits(max_d+1,
                                                  vector< bitset<MAX_M> >(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int d = dist[i][j];
        if (d < INF && d <= max_d)
          layer_bits[d][i].set(j);
      }
    }

    auto shift_mask = [&](const vector< bitset<MAX_M> > &src, int d){
      vector< bitset<MAX_M> > dst(n);
      if (d == 0) {            
        for (int i = 1; i < n; i++)
          dst[i-1] = src[i];
      } else if (d == 1) {     
        for (int i = 0; i+1 < n; i++)
          dst[i+1] = src[i];
      } else if (d == 2) {     
        for (int i = 0; i < n; i++)
          dst[i] = (src[i] >> 1);
      } else {                 
        for (int i = 0; i < n; i++)
          dst[i] = (src[i] << 1);
      }

      for (int i = 0; i < n; i++)
        dst[i] &= grid_free[i];
      return dst;
    };

    int cur_max = max_d;
    string answer;
    while (cur_max > 0) {

      vector< bitset<MAX_M> > frontier(n);
      for (int i = 0; i < n; i++)
        frontier[i] = alive[i] & layer_bits[cur_max][i];

      int best_d = -1, best_new = cur_max;

      for (int d = 0; d < 4; d++) {
        auto f2 = shift_mask(frontier, d);

        bool moved_down = false;
        for (int i = 0; i < n && !moved_down; i++) {
          if ((f2[i] & layer_bits[cur_max - 1][i]).any()) {
            moved_down = true;
          }
        }

        int new_max = moved_down ? cur_max - 1 : cur_max;
        if (new_max < best_new) {
          best_new = new_max;
          best_d   = d;
        }
      }

      if (best_d < 0)
        break;    

      answer.push_back(dc[best_d]);
      alive = shift_mask(alive, best_d);
      cur_max = best_new;
    }

    cout << answer << "\n";
    return 0;
}