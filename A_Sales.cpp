#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Key {
    ll d1, d2;
    bool operator==(Key const &o) const { return d1==o.d1 && d2==o.d2; }
};
struct KeyHash {
    size_t operator()(Key const &k) const noexcept {
        return std::hash<ll>()(k.d1) ^ (std::hash<ll>()(k.d2) << 1);
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; if(!(cin>>n)) return 0;
    vector<ll> l(n), m(n), w(n);
    for(int i=0;i<n;i++) cin>>l[i]>>m[i]>>w[i];
    int n1 = n/2;
    int n2 = n - n1;

    unordered_map<Key, pair<ll,ll>, KeyHash> mp;
    mp.reserve(pow(3,n1));

    ll tot1 = 1;
    for(int i=0;i<n1;i++) tot1 *= 3;
    for(ll code=0; code<tot1; ++code) {
        ll c = code;
        ll sL=0, sM=0, sW=0;
        for(int i=0;i<n1;i++){
            int d = c % 3;
            c /= 3;
            if(d==0){ sL += l[i]; sM += m[i]; }
            else if(d==1){ sL += l[i]; sW += w[i]; }
            else { sM += m[i]; sW += w[i]; }
        }
        ll d1 = sL - sM;
        ll d2 = sL - sW;
        Key key{d1, d2};
        auto it = mp.find(key);
        if(it==mp.end() || it->second.first < sL) {
            mp[key] = {sL, code};
        }
    }

    ll tot2 = 1;
    for(int i=0;i<n2;i++) tot2 *= 3;
    ll best_sum = LLONG_MIN;
    ll best_code1=0, best_code2=0;
    for(ll code=0; code<tot2; ++code) {
        ll c = code;
        ll sL=0, sM=0, sW=0;
        for(int i=0;i<n2;i++){
            int d = c % 3;
            c /= 3;
            int idx = n1 + i;
            if(d==0){ sL += l[idx]; sM += m[idx]; }
            else if(d==1){ sL += l[idx]; sW += w[idx]; }
            else { sM += m[idx]; sW += w[idx]; }
        }
        ll d1 = sL - sM;
        ll d2 = sL - sW;
        Key need{-d1, -d2};
        auto it = mp.find(need);
        if(it != mp.end()) {
            ll totalL = sL + it->second.first;
            if(totalL > best_sum) {
                best_sum = totalL;
                best_code1 = it->second.second;
                best_code2 = code;
            }
        }
    }
    if(best_sum == LLONG_MIN) {
        cout<<"Impossible";
        return 0;
    }

    vector<char> res(n);
    ll c1 = best_code1;
    for(int i=0;i<n1;i++){
        int d = c1 % 3;
        c1 /= 3;
        if(d==0) { res[i] = 'L';  res[i] = 'L';  }
        else if(d==1) res[i] = 'L';
        else res[i] = 'M';
    }

    vector<string> out(n);
    c1 = best_code1;
    for(int i=0;i<n1;i++){
        int d = c1 % 3;
        c1 /= 3;
        if(d==0) out[i] = "LM";
        else if(d==1) out[i] = "LW";
        else out[i] = "MW";
    }
    ll c2 = best_code2;
    for(int i=0;i<n2;i++){
        int d = c2 % 3;
        c2 /= 3;
        int idx = n1 + i;
        if(d==0) out[idx] = "LM";
        else if(d==1) out[idx] = "LW";
        else out[idx] = "MW";
    }
    for(int i=0;i<n;i++) cout<<out[i]<<"\n";
    return 0;
}