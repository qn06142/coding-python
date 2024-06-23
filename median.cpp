#include<bits/stdc++.h>
using namespace std;

int a[5005], sa[5005];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        int count = 0;
        for(int j = 1; j <= n; j++) {
            sa[j] = ((a[j] >= a[i]) ? 1 : -1) + sa[j - 1];
        }

        map<int, int> mapp;
        for(int j = 1; j <= n; j++) {
            count += mapp[sa[j]];
            if(sa[j] == 0 || sa[j] == 1) count++;
            mapp[sa[j]]++;
        }
        fill(sa, sa + n + 1, 0);
        cout << count << ' ';
    }
}
