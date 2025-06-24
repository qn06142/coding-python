#include <bits/stdc++.h>
using namespace std;

// trạng thái (i, dAB, dAC, dAD)
struct State {
    int i, d_ab, d_ac, d_ad;
    bool operator==(State const &o) const {
        return i==o.i && d_ab==o.d_ab && d_ac==o.d_ac && d_ad==o.d_ad;
    }
};
struct StateHash {
    size_t operator()(State const &s) const noexcept {
        // kết hợp i và các diff
        uint64_t h = s.i;
        h = h*1000003 ^ (uint64_t)(s.d_ab+1000000);
        h = h*1000003 ^ (uint64_t)(s.d_ac+1000000);
        h = h*1000003 ^ (uint64_t)(s.d_ad+1000000);
        return h;
    }
};

int n;
vector<int>a,b,c,d;
vector<int>choice;        // lưu kết quả
unordered_set<State,StateHash> visited;
bool dfs(int i, int sa, int sb, int sc, int sd) {
    int d_ab = sa - sb;
    int d_ac = sa - sc;
    int d_ad = sa - sd;
    State st{i, d_ab, d_ac, d_ad};
    if (visited.count(st)) return false;
    if (i == n) {
        if (sa==sb && sa==sc && sa==sd) return true;
        else {
            visited.insert(st);
            return false;
        }
    }
    // 6 cặp: AB, AC, AD, BC, BD, CD
    // mỗi lần gọi dfs(i+1, new sa,sb,sc,sd)
    // và lưu choice[i]=0..5
    // prune cơ bản: ta có thể tính tổng max có thể thêm để cân bằng, nhưng bỏ qua ở đây
    // vì memo sẽ prune nhiều
    // 0: AB
    choice[i] = 0;
    if (dfs(i+1, sa+a[i], sb+b[i], sc, sd)) return true;
    // 1: AC
    choice[i] = 1;
    if (dfs(i+1, sa+a[i], sb, sc+c[i], sd)) return true;
    // 2: AD
    choice[i] = 2;
    if (dfs(i+1, sa+a[i], sb, sc, sd+d[i])) return true;
    // 3: BC
    choice[i] = 3;
    if (dfs(i+1, sa, sb+b[i], sc+c[i], sd)) return true;
    // 4: BD
    choice[i] = 4;
    if (dfs(i+1, sa, sb+b[i], sc, sd+d[i])) return true;
    // 5: CD
    choice[i] = 5;
    if (dfs(i+1, sa, sb, sc+c[i], sd+d[i])) return true;

    visited.insert(st);
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    a.resize(n); b.resize(n); c.resize(n); d.resize(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    for(int i=0;i<n;++i) cin>>c[i];
    for(int i=0;i<n;++i) cin>>d[i];

    choice.assign(n, -1);
    // khởi DFS từ trận 0 với điểm 0
    bool ok = dfs(0,0,0,0,0);
    if(!ok) {
        cout<<"Impossible";
        return 0;
    }
    static const vector<string> mp = {"AB","AC","AD","BC","BD","CD"};
    for(int i=0;i<n;++i){
        cout<<mp[choice[i]];
        if(i+1<n) cout<<"\n";
    }
    return 0;
}
