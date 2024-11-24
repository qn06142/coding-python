#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> divs;
    for(long long i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            if(n / i != i) {
                divs.push_back(i);
                divs.push_back(n / i);
            } else {
                divs.push_back(i);
            }
        }
    }
    sort(divs.begin(), divs.end());
    if(divs.size() < k) {
        cout << -1;
        return 0;
    }
    cout << divs[k - 1];
}