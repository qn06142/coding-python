#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> pqueue;
array<int, 100005> a;
int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	int cost = 0;
	for(int i = 0; i < n; i++) {
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
		pqueue.push(make_pair(a[i], i));
	}
	cout << cost;
}