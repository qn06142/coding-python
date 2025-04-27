#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll K;
    cin >> N >> K;

    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    unordered_map<ll,ll> freq;
    freq.reserve(N*2);
    for(auto x : A) {
        freq[x]++;
    }

    ll ans = 0;
    if (K == 0) {

        ll cz = freq[0];
        ans += cz * (cz - 1) / 2;

        for (auto &p : freq) {
            ll x = p.first, c = p.second;
            if (x < 0) {
                auto it = freq.find(-x);
                if (it != freq.end())
                    ans += c * it->second;
            }
        }
    } else {

        for (auto &p : freq) {
            ll x  = p.first;
            ll cx = p.second;
            ll y  = K - x;
            auto it = freq.find(y);
            if (it == freq.end()) continue;

            if (y > x) {

                ans += cx * it->second;
            }
            else if (y == x) {

                ans += cx * (cx - 1) / 2;
            }
        }

        for (auto &p : freq) {
            ll x  = p.first;
            ll cx = p.second;
            ll y  = -K - x;
            auto it = freq.find(y);
            if (it == freq.end()) continue;

            if (y > x) {
                ans += cx * it->second;
            }
            else if (y == x) {
                ans += cx * (cx - 1) / 2;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}