#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    #define int long long
    int n, k, l, x;
    cin >> n >> k >> l;
    deque<int> dq(n);

    for (int i = 0; i < n; ++i) {
        cin >> dq[i];
    }
    cin >> x;

    int netShift = (k - l) % n;
    if (netShift < 0) {
        netShift += n;
    }

    int effectiveShift = (x * netShift) % n;

    if (effectiveShift > 0) {

        for (int i = 0; i < effectiveShift; ++i) {
            int front = dq.front();
            dq.pop_front();
            dq.push_back(front);
        }
    } else if (effectiveShift < 0) {

        effectiveShift = -effectiveShift;
        for (int i = 0; i < effectiveShift; ++i) {
            int back = dq.back();
            dq.pop_back();
            dq.push_front(back);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << dq[i] << " ";
    }
    cout << endl;

    return 0;
}