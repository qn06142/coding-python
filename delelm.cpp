#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
deque<int> a;

int main() {
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        sum += a.front();
    }
    sort(a.begin(), a.end());
    int ans = 0;
    while(sum != 0) {
        ans++;
        if(sum > 0) {
            sum -= a.front();
            a.pop_back();
        }
        else {
            sum -= a.back();
            a.pop_front();
        }
    }
    cout << ans;
}