#include<iostream>
#include<set>
#include<map>
using namespace std;
set<int> a;
int b[(int) 1e5 + 5];
map<int, int> c;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        a.insert(tmp);
        b[i] = tmp;
        c[tmp]++;
    }
    if(a.size() > 2) {
        cout << 0;
        return 0;
    } else {
        for(int i = 0; i < n; i++) {
            if(c[b[i]] == 1) {
                cout << i+1;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}
