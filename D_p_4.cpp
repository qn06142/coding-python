#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n; cin >> n;
    vector<int> a(n);
    for(auto &it: a) cin >> it;

    priority_queue<int, vector<int>, greater<int>> pq;

    ll res = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        pq.push(a[i]);

        while(sum < 0) { // nếu tổng tiền hiện tại bị âm
            sum -= pq.top(); // trừ đi số tiền nhỏ nhất
            pq.pop(); // và loại bỏ nó khỏi hàng đợi
        }

        res = max(res, sum); // cập nhật lợi nhuận lớn nhất
    }

    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}