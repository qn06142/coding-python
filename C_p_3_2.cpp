#include <iostream>
using namespace std;

long seg[1 << 18];

long build(long node, long beg, long en, bool toggle) {
    if (beg == en) {
        long temp;
        cin >> temp;
        seg[node] = temp;
        return seg[node];
    }
    long mid = (beg + en) / 2;
    long l = build(2 * node, beg, mid, !toggle);
    long r = build(2 * node + 1, mid + 1, en, !toggle);

    if (toggle)
        seg[node] = l | r;
    else
        seg[node] = l ^ r;

    return seg[node];
}

void update(long node, long l, long r, long index, long value, int toggle) {
    if (l == r) {
        seg[node] = value;
        return;
    }

    long mid = (l + r) / 2;
    if (index <= mid)
        update(2 * node, l, mid, index, value, !toggle);
    else
        update(2 * node + 1, mid + 1, r, index, value, !toggle);

    if (toggle)
        seg[node] = seg[2 * node] | seg[2 * node + 1];
    else
        seg[node] = seg[2 * node] ^ seg[2 * node + 1];
}

int main() {
    int n;
    cin >> n;
    long m;
    cin >> m;
    build(1, 1, 1 << n, n);

    long p, b;
    while (m--) {
        cin >> p >> b;
        update(1, 1, 1 << n, p, b, n);
        cout << seg[1] << '\n';
    }

    return 0;
}
