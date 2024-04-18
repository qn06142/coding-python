#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m, M;
    cin >> n >> m >> M;
    vector<long long> a(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    int left = 1, right = 1;
    long long sum = 0, count = 0;
    while(right <= n){
        sum += a[right];
        while(sum > M){
            sum -= a[left];
            left++;
        }
        if(sum >= m){
            count += right - left + 1;
        }
        right++;
    }

    cout << count << "\n";

    return 0;
}
