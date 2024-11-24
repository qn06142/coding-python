#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    long long n, m;
    cin >> n >> m;
    long long tmp = 1;
    vector<int> maxes;
    for(int i = 1; i <= n; i++){
        tmp = (tmp * i) % m;
        maxes.push_back(tmp);
    }
    cout << *max_element(maxes.begin(), maxes.end());
}