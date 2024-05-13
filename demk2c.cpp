#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int count = 0;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n * m; i++) {
        int tmp;
        cin >> tmp;
        count += tmp == k ? 1 : 0;
    }
    cout << count;
}