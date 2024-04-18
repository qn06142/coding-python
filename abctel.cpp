#include<iostream>
#include<algorithm>

using namespace std;
pair<int, int> a[(int) 1e5 + 5];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i].second;
        cin >> a[i].first;
    }
    sort(a, a + n);
    vector<int> maxserved;
    for(int i = 0; i < n; i++) {
        int tmp = upper_bound(a, a + n, 2k + a[i]);
        maxserved.push_back();
    }
    cout << max(maxserved);
}