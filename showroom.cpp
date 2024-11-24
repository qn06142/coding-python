#include<iostream>

using namespace std;

pair<int, int> yes;
int n;
int bacctracc(int i = 0, int s = 0, int a = INT_MAX, int b = INT_MIN) {
    if(i > n) return (s - (a - b));
    else return max(bacctracc(i + 1, s, a, b), bacctracc(i + 1, s + yes[i].second, max(a, yes[i]first), min(b, yes[i].first)));
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> yes[i].first >> yes[i].second;
    }
    cout << bacctracc();
}