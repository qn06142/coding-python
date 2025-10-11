#include <bits/stdc++.h>
using namespace std;

const int N = 7;
int used = 0;
int QUERY_LIMIT = 12;

int ask(int l, int r) {
    cout << l << ' ' << r << endl;
    cout.flush();
    int res;
    if (!(cin >> res)) exit(0);
    if (res == -1) exit(0);
    used++;
    return res;
}

int eval(const vector<int> &p, int l, int r) {
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = l-1; i <= r-1; ++i) {
        mn = min(mn, p[i]);
        mx = max(mx, p[i]);
    }
    return mx - mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l = 1, r = N, pos7 = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int t = ask(1, mid);
        if (t < N - 1) { 
            l = mid + 1;
        } else {
            pos7 = mid;
            r = mid - 1;
        }
    }
    if (pos7 == -1) return 0;

    int l2 = 1, r2 = pos7 - 1, pos1 = -1;
    while (l2 <= r2) {
        int mid = (l2 + r2) / 2;
        int t = ask(mid, pos7);
        if (t < N - 1) {
            r2 = mid - 1;
        } else {
            pos1 = mid;
            l2 = mid + 1;
        }
    }
    if (pos1 == -1) return 0;

    vector<int> base;
    for (int i = 1; i <= N; ++i) base.push_back(i);
    vector<vector<int>> cand;
    do {
        if (base[pos1 - 1] == 1 && base[pos7 - 1] == 7) {
            cand.push_back(base);
        }
    } while (next_permutation(base.begin(), base.end()));

    if (cand.empty()) return 0;

    map<pair<int,int>, int> known;

    while ((int)cand.size() > 1 && used < QUERY_LIMIT) {
        int l_ = -1, r_ = -1;
        int worst = INT_MAX;

        for (int L = 1; L <= N; ++L) {
            for (int R = L; R <= N; ++R) {
                if (known.count({L,R})) continue; 

                unordered_map<int,int> cnt;
                for (auto &perm : cand) {
                    int val = eval(perm, L, R);
                    cnt[val]++;
                }
                int worst = 0;
                for (auto &kv : cnt) worst = max(worst, kv.second);
                if (worst < worst) {
                    worst = worst;
                    l_ = L; r_ = R;
                }
            }
        }

        if (l_ == -1 || worst >= (int)cand.size()) break;

        int got = ask(l_, r_);
        known[{l_,r_}] = got;

        vector<vector<int>> filtered;
        filtered.reserve(cand.size());
        for (auto &perm : cand) {
            if (eval(perm, l_, r_) == got) filtered.push_back(perm);
        }
        cand.swap(filtered);
    }

    for (int i = 1; (int)cand.size() > 1 && used < QUERY_LIMIT && i < N; ++i) {
        if (known.count({i, i+1})) continue;
        int got = ask(i, i+1);
        known[{i, i+1}] = got;
        vector<vector<int>> filtered;
        filtered.reserve(cand.size());
        for (auto &perm : cand) {
            if (eval(perm, i, i+1) == got) filtered.push_back(perm);
        }
        cand.swap(filtered);
    }

    vector<int> ans = cand[0];

    for (int i = 0; i < N; ++i) {
        cout << ans[i] <<  ' ';
    }
}