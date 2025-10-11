#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
const ll INF = (ll)1e18;

int n, k;
vector<int> a;
const int maxid = 10001;
vector<list<int>> pos_lists(maxid); 
vector<int> cur_pos(maxid, 0);  
vector<ll> next_use;
vector<list<int>> levels;
ll moves = 0;

int pick_latest(list<int>& Layer)
{
    if (next_use[Layer.front()] > next_use[Layer.back()])
    swap(Layer.front(), Layer.back());
    int res = Layer.back();
    Layer.pop_back();
    return res;
}
void Receive(int j, int x) {
    if (j != 0 && levels[j].size() == 2) {
        int y = pick_latest(levels[j]);
        Receive(j - 1, y);
        return;
    }
    levels[j + 1].remove(x);
    levels[j].push_back(x);
    cur_pos[x] = j;
    ++moves;
}

void Request(int i, int x)
{
    if (cur_pos[x] == i) return;
    if (levels[i].size() == 2)
    {
    int y = pick_latest(levels[i]);
    Receive(i - 1, y);
    }
    Request(i - 1, x);
    if (i - 1 != 0)
    levels[i - 1].remove(x);
    levels[i].push_back(x);
    cur_pos[x] = i;
    ++moves;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> k)) return 0;
    a.resize(k);
    for (int i = 0; i < k; ++i) cin >> a[i];

    for (int i = 0; i < k; ++i) {
        pos_lists[a[i]].push_back(i);
    }

    unordered_set<int> tools(a.begin(), a.end());
    levels.assign(n + 2, list<int>());
    next_use.assign(1e4 + 2, 0);
    for (int t : tools) {

        next_use[t] = pos_lists[t].front();

        cur_pos[t] = 0;
        levels[0].push_back(t);
    }

    for (int idx = 0; idx < k; ++idx) {
        int x = a[idx];

        pos_lists[x].pop_front();

        next_use[x] = pos_lists[x].empty() ? INF : pos_lists[x].front();
        Request(n, x);
    }

    for (int level = n; level >= 1; --level) {
        while (!levels[level].empty()) {
            int t = levels[level].front();
            while (cur_pos[t] > 0) {
                Receive(cur_pos[t] - 1, t);
            }
        }
    }

    cout << moves << '\n';
}