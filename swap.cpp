#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

void build(vector<ll>& seg, const vector<ll>& arr, int siz) {
    int size = arr.size();

    for (int i = 0; i < size; i++) {
        seg[siz + i] = arr[i];
    }

    for (int i = size; i < siz; i++) {
        seg[siz + i] = 0;
    }

    for (int i = siz - 1; i > 0; i--) {
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }
}

int query(const vector<ll>& seg, int siz, int canisiz, ll x) {

    if (seg[1] <= x)
        return -1;
    int idx = 1;

    while (idx < siz) {
        if (seg[2 * idx] > x) {
            idx = 2 * idx;
        } else {
            idx = 2 * idx + 1;
        }
    }
    int pos = idx - siz; 
    if (pos >= canisiz)
        return -1;
    return pos;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    ll S;
    cin >> S; 

    vector<ll> candidate;
    for (int i = K; i < N; i++){
        candidate.push_back(A[i]);
    }
    int canisiz = candidate.size();

    int siz = 1;
    while(siz < canisiz) {
        siz *= 2;
    }
    vector<ll> seg(2 * siz, 0);
    build(seg, candidate, siz);

    ll ans = LLONG_MAX;

    for (int i = 0; i < K; i++){
        int pos = query(seg, siz, canisiz, A[i]);
        if (pos != -1) {
            int j = K + pos; 
            ans = min(ans, (ll)(j - i));
        }
    }
    if(ans == LLONG_MAX)
        cout << -1 << "\n";
    else
        cout << ans << "\n";

    return 0;
}