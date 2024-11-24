    #include <bits/stdc++.h>
     
    using namespace std;
     
    const int maxN = 1e6 + 5;
     
    int n;
    int a[maxN], b[maxN];
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
     
     
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        deque<int> dq;
        int res = 1;
        int ind = 0;
        for (int i = 1; i <= n; i++) {
            while (!dq.empty() && a[dq.front()] > b[i]) {
                ind++;
                if (dq.front() == ind) {
                    dq.pop_front();
                }
            }
            while (!dq.empty() && a[dq.back()] < a[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            res = max(res, i - ind);
        }
        cout << res;
    }