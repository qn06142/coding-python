#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a;
set<int> b;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        b.insert(tmp);
    }
    for(auto i:b) a.push_back(i);
    sort(a.begin(), a.end());
    cout << a.size() << endl;
    for(auto i:a) cout << i << " ";
}