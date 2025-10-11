#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 100000;

int n, m;
int block_size;
int a[MAXN+2], nxt[MAXN+2], cnt[MAXN+2], lpos[MAXN+2];

inline int bid(int i) {
    return (i - 1) / block_size;
}

void refresh(int b) {
    int L = b * block_size + 1;
    int R = min(n, (b + 1) * block_size);
    for (int i = R; i >= L; --i) {
        int j = i + a[i];
        if (j > n) {

            nxt[i] = n + 1;
            cnt[i] = 1;
            lpos[i] = i;
        }
        else if (bid(j) == b) {

            nxt[i] = nxt[j];
            cnt[i] = cnt[j] + 1;
            lpos[i] = lpos[j];
        }
        else {

            nxt[i] = j;
            cnt[i] = 1;
            lpos[i] = i;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    block_size = max(1, int(sqrt(n)));

    int num_blocks = (n + block_size - 1) / block_size;
    for (int b = 0; b < num_blocks; ++b) {
        refresh(b);
    }

    while (m--) {
        int type; 
        cin >> type;
        if (type == 0) {

            int pos, val;
            cin >> pos >> val;
            a[pos] = val;
            refresh(bid(pos));
        } 
        else {

            int pos; 
            cin >> pos;
            int jmps = 0;
            int last = pos;

            while (pos <= n) {
                jmps += cnt[pos];
                last = lpos[pos];
                pos = nxt[pos];
            }

            cout << last << " " << jmps << "\n";
        }
    }
}