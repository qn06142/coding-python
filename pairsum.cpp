#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int a[(int) 2e5 + 5];
int main (){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    map<int, int> themap;
    long long count = 0;
    for(int i = 1; i <= n; i++) {
        themap[a[i]]++;
        if(a[i] < k && themap[k - a[i]] > 0)
            count += themap[k - a[i]];
    }
    cout << count;
}
//Wheatley1901