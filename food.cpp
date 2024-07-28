#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqueue;
int a[(int) 1e5 + 5];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    long long cost = 0;
    for(int i = 1; i <= n; i++) {
        while(!pqueue.empty()) {
            if(i - pqueue.top().second >= k) {
                pqueue.pop();
            } else {
                break;
            }
        }
        if(pqueue.empty()) {
            cost += a[i] * 2;
        } else {
            cost += min(pqueue.top().first, a[i]) * 2;
        }
        pqueue.emplace(a[i], i);
    }
    cout << cost;
}
