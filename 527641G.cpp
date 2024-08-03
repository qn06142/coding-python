#include <iostream>
#include <vector>

using namespace std;

vector<int> a[22];
int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        a[s.size()].push_back(i);
    }

    long long res = 0;
    for (int s = 2; s <= 20; ++s)
    {
        for (int l = 0, r = 0; r < (int) a[s].size(); ++r)
        {
            while (a[s][r] - a[s][l] > k) ++l;
            res += r - l;
        }
    }

    cout << res;
    return 0;
}
