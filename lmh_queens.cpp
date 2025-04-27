#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Q {
    int r, c, i;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    int n;
    cin >> k >> n;

    vector<Q> qs(n);
    for (int j = 0; j < n; j++){
        cin >> qs[j].r >> qs[j].c;
        qs[j].i = j;
    }

    unordered_map<int, vector<int>> row;
    unordered_map<int, vector<int>> col;
    unordered_map<long long, vector<int>> diag;   
    unordered_map<long long, vector<int>> adiag;    

    for (auto &q : qs) {
        row[q.r].push_back(q.c);
        col[q.c].push_back(q.r);
        long long d = (long long)q.r - q.c;
        diag[d].push_back(q.r);
        long long a = (long long)q.r + q.c;
        adiag[a].push_back(q.r);
    }

    for (auto &e : row)
        sort(e.second.begin(), e.second.end());
    for (auto &e : col)
        sort(e.second.begin(), e.second.end());
    for (auto &e : diag)
        sort(e.second.begin(), e.second.end());
    for (auto &e : adiag)
        sort(e.second.begin(), e.second.end());

    vector<long long> res(n, 0);

    for (auto &q : qs) {
        int r = q.r, c = q.c;
        long long tot = 0;

        {
            auto &vec = row[r];
            int cnt = c - 1;
            auto it = lower_bound(vec.begin(), vec.end(), c);
            if (it != vec.begin()){
                int prev = *(it - 1);
                cnt = c - prev - 1;
            }
            tot += cnt;
        }

        {
            auto &vec = row[r];
            int cnt = k - c;
            auto it = upper_bound(vec.begin(), vec.end(), c);
            if (it != vec.end()){
                int nxt = *it;
                cnt = nxt - c - 1;
            }
            tot += cnt;
        }

        {
            auto &vec = col[c];
            int cnt = r - 1;
            auto it = lower_bound(vec.begin(), vec.end(), r);
            if (it != vec.begin()){
                int prev = *(it - 1);
                cnt = r - prev - 1;
            }
            tot += cnt;
        }

        {
            auto &vec = col[c];
            int cnt = k - r;
            auto it = upper_bound(vec.begin(), vec.end(), r);
            if (it != vec.end()){
                int nxt = *it;
                cnt = nxt - r - 1;
            }
            tot += cnt;
        }

        {
            long long key = (long long)r - c;
            auto &vec = diag[key];
            int cnt = min(r - 1, c - 1);
            auto it = lower_bound(vec.begin(), vec.end(), r);
            if (it != vec.begin()){
                int prev = *(it - 1);
                cnt = r - prev - 1;
            }
            tot += cnt;
        }

        {
            long long key = (long long)r - c;
            auto &vec = diag[key];
            int cnt = min((int)(k - r), (int)(k - c));
            auto it = upper_bound(vec.begin(), vec.end(), r);
            if (it != vec.end()){
                int nxt = *it;
                cnt = nxt - r - 1;
            }
            tot += cnt;
        }

        {
            long long key = (long long)r + c;
            auto &vec = adiag[key];
            int cnt = min(r - 1, (int)(k - c));
            auto it = lower_bound(vec.begin(), vec.end(), r);
            if (it != vec.begin()){
                int prev = *(it - 1);
                cnt = r - prev - 1;
            }
            tot += cnt;
        }

        {
            long long key = (long long)r + c;
            auto &vec = adiag[key];
            int cnt = min((int)(k - r), c - 1);
            auto it = upper_bound(vec.begin(), vec.end(), r);
            if (it != vec.end()){
                int nxt = *it;
                cnt = nxt - r - 1;
            }
            tot += cnt;
        }

        res[q.i] = tot;
    }

    for (int j = 0; j < n; j++){
        cout << res[j] << "\n";
    }

    return 0;
}
