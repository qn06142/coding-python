#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 5;

int a[MAXN];
int freq[MAXN], count[MAXN];
int answer[MAXN];
int current_answer = 0;

struct Query {
    int l, r, idx;
};

bool compare(const Query &a, const Query &b) {
    int block_size = sqrt(MAXN);
    if (a.l / block_size != b.l / block_size)
        return a.l / block_size < b.l / block_size;
    return a.r < b.r;
}

void add(int x) {
    if(x > 1e5 + 5) {
        return;
    }
    if (freq[x] == x) current_answer--;
    freq[x]++;
    if (freq[x] == x) current_answer++;
}

void remove(int x) {
    if(x > 1e5 + 5) {
        return;
    }
    if (freq[x] == x) current_answer--;
    freq[x]--;
    if (freq[x] == x) current_answer++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<Query> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end(), compare);

    int current_l = 1, current_r = 0;

    for (int i = 0; i < m; i++) {
        int l = queries[i].l;
        int r = queries[i].r;

        while (current_r < r) {
            current_r++;
            add(a[current_r]);
        }
        while (current_r > r) {
            remove(a[current_r]);
            current_r--;
        }
        while (current_l < l) {
            remove(a[current_l]);
            current_l++;
        }
        while (current_l > l) {
            current_l--;
            add(a[current_l]);
        }

        answer[queries[i].idx] = current_answer;
    }

    for (int i = 0; i < m; i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}
