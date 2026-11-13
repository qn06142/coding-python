#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

int n, k;
int a[maxn][maxn];
bool fixed_[maxn][maxn];
bitset<maxn> cand[maxn][maxn];

unsigned long long seed = 88172645463325252ULL;

inline unsigned long long rnd() {
    seed ^= seed << 7;
    seed ^= seed >> 9;
    return seed;
}

void eliminate(int r, int c, int v, queue<pair<int, int>> &q) {
    int br = r / k * k;
    int bc = c / k * k;

    for (int i = 0; i < n; i++) {
        if (i != c && !a[r][i] && cand[r][i][v]) {
            cand[r][i].reset(v);
            if (cand[r][i].count() == 1)
                q.push({r, i});
        }

        if (i != r && !a[i][c] && cand[i][c][v]) {
            cand[i][c].reset(v);
            if (cand[i][c].count() == 1)
                q.push({i, c});
        }
    }

    for (int i = br; i < br + k; i++) {
        for (int j = bc; j < bc + k; j++) {
            if ((i != r || j != c) && !a[i][j] && cand[i][j][v]) {
                cand[i][j].reset(v);
                if (cand[i][j].count() == 1)
                    q.push({i, j});
            }
        }
    }
}

void assign(int r, int c, int v, queue<pair<int, int>> &q) {
    a[r][c] = v;
    cand[r][c].reset();
    cand[r][c].set(v);
    eliminate(r, c, v, q);
}

void init(queue<pair<int, int>> &q) {
    bitset<maxn> mask;

    for (int v = 1; v <= n; v++)
        mask.set(v);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cand[i][j] = mask;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fixed_[i][j]) {
                int v = a[i][j];
                cand[i][j].reset();
                cand[i][j].set(v);
                eliminate(i, j, v, q);
            }
        }
    }
}

void propagate() {
    queue<pair<int, int>> q;
    init(q);

    bool changed = true;

    while (changed) {
        changed = false;

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if (a[r][c] || cand[r][c].count() == 0)
                continue;

            int v = 1;
            while (v <= n && !cand[r][c][v])
                v++;

            if (v <= n) {
                assign(r, c, v, q);
                fixed_[r][c] = true;
                changed = true;
            }
        }

        for (int r = 0; r < n; r++) {
            for (int v = 1; v <= n; v++) {
                int cnt = 0, c = -1;

                for (int j = 0; j < n; j++) {
                    if (a[r][j] == v) {
                        cnt = -1;
                        break;
                    }

                    if (!a[r][j] && cand[r][j][v]) {
                        cnt++;
                        c = j;
                    }
                }

                if (cnt == 1) {
                    assign(r, c, v, q);
                    fixed_[r][c] = true;
                    changed = true;
                }
            }
        }

        for (int c = 0; c < n; c++) {
            for (int v = 1; v <= n; v++) {
                int cnt = 0, r = -1;

                for (int i = 0; i < n; i++) {
                    if (a[i][c] == v) {
                        cnt = -1;
                        break;
                    }

                    if (!a[i][c] && cand[i][c][v]) {
                        cnt++;
                        r = i;
                    }
                }

                if (cnt == 1) {
                    assign(r, c, v, q);
                    fixed_[r][c] = true;
                    changed = true;
                }
            }
        }

        for (int br = 0; br < n; br += k) {
            for (int bc = 0; bc < n; bc += k) {
                for (int v = 1; v <= n; v++) {
                    int cnt = 0, r = -1, c = -1;

                    for (int i = br; i < br + k; i++) {
                        for (int j = bc; j < bc + k; j++) {
                            if (a[i][j] == v) {
                                cnt = -1;
                                break;
                            }

                            if (!a[i][j] && cand[i][j][v]) {
                                cnt++;
                                r = i;
                                c = j;
                            }
                        }
                    }

                    if (cnt == -1) break;

                    if (cnt == 1) {
                        assign(r, c, v, q);
                        fixed_[r][c] = true;
                        changed = true;
                    }
                }
            }
        }
    }
}

void fill() {
    for (int br = 0; br < n; br += k) {
        for (int bc = 0; bc < n; bc += k) {
            bool used[maxn] = {};
            int x[maxn], y[maxn], missing[maxn];
            int cnt = 0, sz = 0;

            for (int i = br; i < br + k; i++) {
                for (int j = bc; j < bc + k; j++) {
                    if (a[i][j]) {
                        used[a[i][j]] = true;
                    } else {
                        x[++cnt] = i;
                        y[cnt] = j;
                    }
                }
            }

            for (int v = 1; v <= n; v++)
                if (!used[v])
                    missing[++sz] = v;

            for (int i = 1; i <= cnt; i++)
                a[x[i]][y[i]] = (i <= sz ? missing[i] : 1);
        }
    }
}

void anneal() {
    auto start_time = chrono::steady_clock::now();
    const double time_limit = 1.4;

    vector<pair<int, int>> free_cells[maxn];
    vector<int> active_blocks;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (!fixed_[r][c]) {
                int b = r / k * k + c / k;
                free_cells[b].push_back({r, c});
            }
        }
    }

    for (int b = 0; b < n; b++) {
        if (free_cells[b].size() >= 2)
            active_blocks.push_back(b);
    }

    if (active_blocks.empty()) return;

    static int row_cnt[maxn][maxn];
    static int col_cnt[maxn][maxn];
    memset(row_cnt, 0, sizeof(row_cnt));
    memset(col_cnt, 0, sizeof(col_cnt));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int v = a[r][c];
            row_cnt[r][v]++;
            col_cnt[c][v]++;
        }
    }

    int cur_cost = 0;
    for (int i = 0; i < n; i++) {
        for (int v = 1; v <= n; v++) {
            if (row_cnt[i][v] > 1) cur_cost += row_cnt[i][v] * (row_cnt[i][v] - 1) / 2;
            if (col_cnt[i][v] > 1) cur_cost += col_cnt[i][v] * (col_cnt[i][v] - 1) / 2;
        }
    }

    int best_cost = cur_cost;
    static int best_a[maxn][maxn];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            best_a[i][j] = a[i][j];

    double t_start = 3.0;
    double t_end = 0.001;
    double temp = t_start;

    unsigned int iter = 0;
    while (true) {
        iter++;
        if ((iter & 4095) == 0) {
            double elapsed = chrono::duration<double>(chrono::steady_clock::now() - start_time).count();
            if (elapsed >= time_limit) break;
            temp = t_start * pow(t_end / t_start, elapsed / time_limit);
        }

        int b = active_blocks[rnd() % active_blocks.size()];
        int sz = free_cells[b].size();
        int idx1 = rnd() % sz;
        int idx2 = rnd() % (sz - 1);
        if (idx2 >= idx1) idx2++;

        int r1 = free_cells[b][idx1].first;
        int c1 = free_cells[b][idx1].second;
        int r2 = free_cells[b][idx2].first;
        int c2 = free_cells[b][idx2].second;

        int u = a[r1][c1];
        int v = a[r2][c2];
        if (u == v) continue;

        int delta = 0;
        if (r1 != r2) {
            delta += (row_cnt[r1][v] - row_cnt[r1][u] + 1) +
                     (row_cnt[r2][u] - row_cnt[r2][v] + 1);
        }
        if (c1 != c2) {
            delta += (col_cnt[c1][v] - col_cnt[c1][u] + 1) +
                     (col_cnt[c2][u] - col_cnt[c2][v] + 1);
        }

        if (delta <= 0 || (temp > 1e-5 && double(rnd() & 0xFFFFFFFF) / 4294967296.0 < exp(-delta / temp))) {
            if (r1 != r2) {
                row_cnt[r1][u]--; row_cnt[r1][v]++;
                row_cnt[r2][v]--; row_cnt[r2][u]++;
            }
            if (c1 != c2) {
                col_cnt[c1][u]--; col_cnt[c1][v]++;
                col_cnt[c2][v]--; col_cnt[c2][u]++;
            }
            a[r1][c1] = v;
            a[r2][c2] = u;
            cur_cost += delta;

            if (cur_cost < best_cost) {
                best_cost = cur_cost;
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        best_a[i][j] = a[i][j];
                if (best_cost == 0) break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = best_a[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    k = round(sqrt(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            fixed_[i][j] = (a[i][j] != 0);
        }
    }

    propagate();
    fill();
    anneal();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << (j == n - 1 ? '\n' : ' ');
    }
}