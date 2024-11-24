#include <iostream>
#include <vector>
using namespace std;
#define int long long 
int f(const vector<int>& a) {
    int ret = 0, s = 0;
    for (int x : a) {
        if (x == 1) {
            ret += s * (s + 1) / 2;
            s = 0;
        } else {
            s += 1;
        }
    }
    ret += s * (s + 1) / 2;
    return ret;
}

signed main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> noxy (N, 0), noy (N, 0), nox (N, 0), xy (N, 0);

    for (int i = 0; i < N; ++i) {
        if (!(Y <= A[i] && A[i] <= X)) {
            noxy[i] = 1;
            noy[i] = 1;
            nox[i] = 1;
            xy[i] = 1;
        }
        if (A[i] == X) {
            noy[i] = 1;
            xy[i] = 1;
        }
        if (A[i] == Y) {
            nox[i] = 1;
            xy[i] = 1;
        }
    }

    cout << f(noxy) - f(noy) - f(nox) + f(xy) << endl;

    return 0;
}
