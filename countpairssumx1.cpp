#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()          
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    map<int, int> M;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        M[tmp]++;
    }

    long long res = 0;
    for (pair<int, int> e : M)
    {
        int vx = e.first;
        int vy = k - vx;
        if (vx > vy) break;

        int fx = M[vx];
        int fy = M[vy];

        if (vx == vy)
            res += 1LL * fx * (fx - 1) / 2;
        else 
            res += 1LL * fx * fy;
    }

    cout << res;
    return 0;
}
