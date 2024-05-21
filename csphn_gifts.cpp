#include<iostream>
#include<vector>

using namespace std;
int a[(int) 1e6 + 5];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 1e9;
    for(int i = 1; i <= n - k; i++) {
        vector<int> tmp;
        for(int i_ = 1; i_ < i; i_++) {
            tmp.push_back(a[i_]);
        }
        for(int i_ = i + k  + 1; i_ <= n; i_++) {
            tmp.push_back(a[i_]);
        }
        int tmp1 = 0;
        for(int i_ = 0; i_ < (int) tmp.size() - k; i_++) {
            int tmp2 = 0;
            for(int j = i_; j <= i_ + k; j++) {
                tmp2 += tmp[j];
            }
            tmp1 = max(tmp1, tmp2);
        }
        //if(tmp1 == 0) for(int i:tmp) cout << i << " ";
        ans = min(ans, tmp1);
    }
    cout << ans;
}