#include<bits/stdc++.h>

using namespace std;
string a[(int) 1e5 + 5];
int a1[(int) 1e5 + 5];
long long power10[(int) 18];
void powint() {
    long long base = 10, power = 16;
    long long ans = 1;
    for(int i = 1; i <= power; i++) {
        ans *= base;
        power10[i] = ans;
    }
}
long long check(int x, int y, int k) {
    long long ans = 0;
    ans = ((long long) a1[x]) * (long long) power10[y] % k;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    /*while(true) {
        string tmp, tmp1;
        int tmp2;
        cin >> tmp >> tmp1 >> tmp2;
        cout << check(tmp, tmp1, tmp2);
    }*/
    powint();
    for(int i = 1; i <= q; i++) {
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            a1[i] = stoi(a[i]);
        }
        map<long long, long long> mp[20];
        long long count = 0;
        for(int i = 1; i <= n; i++) {
            for(int len = 1; len <= 9; len++) {
                count += mp[len][check(i, len, k) % k];
            }
            mp[a[i].size()][(-a1[i] % k + k) % k]++;
        }
        for(int i = 0; i < 20; i++) {
            mp[i].clear();
        }

        for(int i = n; i > 0; i--) {
            for(int len = 9; len >= 1; len--) {
                count += mp[len][check(i, len, k) % k];
            }
            mp[a[i].size()][(-a1[i] % k + k) % k]++;
        }
        cout << count << "\n";
    }
}