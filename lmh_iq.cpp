#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1000000000;

struct Interval {
    int start, end, id;
    bool operator<(Interval const& o) const {
        return start < o.start;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> l(n), d(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    for(int j = 0; j < n; j++) cin >> d[j];

    // 1) Tạo 2n interval
    long double inv_sqrt2 = 1.0L / sqrtl(2.0L);
    vector<Interval> intervals;
    intervals.reserve(2*n);
    for(int j = 0; j < n; j++){
        int max_l = floor(d[j] * inv_sqrt2 + 1e-12);
        intervals.push_back({0, max_l, j});
        intervals.push_back({d[j], INF, j});
    }
    sort(intervals.begin(), intervals.end(),
         [](auto &A, auto &B){ return A.start < B.start; });

    // 2) Sắp xếp squares theo l
    vector<pair<int,int>> sq(n);
    for(int i = 0; i < n; i++) sq[i] = {l[i], i};
    sort(sq.begin(), sq.end());

    // 3) Quét
    vector<int> p(n, -1);
    vector<char> used(n, 0);
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    int ev = 0;
    for(auto [lv, i] : sq){
        // Đưa vào heap tất cả interval đã bắt đầu
        while(ev < (int)intervals.size() && intervals[ev].start <= lv) {
            pq.emplace(intervals[ev].end, intervals[ev].id);
            ev++;
        }
        // Lọc bỏ interval không dùng được
        while(!pq.empty()) {
            auto [ed, j] = pq.top();
            if(ed < lv || used[j]) {
                pq.pop();
            } else {
                break;
            }
        }
        if(pq.empty()){
            // Không thể ghép → input không hợp lệ
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        auto [ed, j] = pq.top(); pq.pop();
        used[j] = 1;
        p[i] = j + 1;  // chuyển sang 1-based
    }

    // 4) In kết quả
    for(int i = 0; i < n; i++){
        cout << p[i] << (i+1<n? ' ':'\n');
    }
    return 0;
}
