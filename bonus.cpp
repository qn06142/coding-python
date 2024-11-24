#include <bits/stdc++.h>
using namespace std;
map<long long, long long> divs;
int main() {
    long long n, m;
    cin >> n >> m;
    long long ans = 1;
    for (int i = 2; i <= sqrt(n); i++) { 
        int cnt = 0;
        while (n % i == 0) { 
            cnt ++;
            n = n/i; 
        } 
        divs[i] += cnt;
    } 
    if(n != 1) divs[n]++;
    for (int i = 2; i <= sqrt(m); i++) { 
        int cnt = 0;
        while (m % i == 0) { 
            cnt ++;
            m = m/i; 
        } 
        divs[i] += cnt;
    } 
    if(m != 1) divs[m]++;
    for(const auto &i:divs) {
        //cout << i.second << ':' << i.first << ' ';
        ans *= i.second  + 1;
    }
    cout << ans;
}
