#include<iostream>
#include<climits>
#define maxn (int) 5e5 + 5
using namespace std;
long long pref[maxn], a[maxn];

int main() {
    int n, h;
    cin >> n >> h;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        if(i % 2){
            pref[a[i] + 1] -= 1;
            pref[0] += 1;
        } else {
            pref[h - a[i] + 1] += 1;
            pref[h + 1] -= 1;
        }
    }
    //for(int i = 1; i <= n; i++) cout << " " << pref[i];
    //cout << endl;
    for(int i = 1; i <= h; i++) pref[i] += pref[i - 1];
    //for(int i = 1; i <= h; i++) cout << " " << pref[i];
    long long min_ = INT_MAX;
    for(int i = 1; i <= h; i++) {
        min_ = min(min_, pref[i]);
    }
    int count = 0;
    for(int i = 1; i <= h; i++) if(pref[i] == min_) count++;
    cout << min_ << " " << count;
}