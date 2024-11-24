#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
long long prefixSum[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, Q;
    cin >> n >> Q;
    for(int i=1; i<=n; i++){
        cin >> prefixSum[i];
        prefixSum[i] += prefixSum[i-1];
    }

    while(Q--){
        int u, v;
        cin >> u >> v;
        long long total = prefixSum[v] - prefixSum[u-1];
        long long half = total / 2;
        int pos = lower_bound(prefixSum+u, prefixSum+v+1, half+prefixSum[u-1]) - prefixSum;
        long long diff1 = abs(total - 2*(prefixSum[pos] - prefixSum[u-1]));
        long long diff2 = abs(total - 2*(prefixSum[pos-1] - prefixSum[u-1]));
        cout << min(diff1, diff2) << "\n";
    }

    return 0;
}
