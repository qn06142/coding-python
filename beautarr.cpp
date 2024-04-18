#include<iostream>
#include<map>
using namespace std;
int a[(int) 1e5 + 5];
int freq[(int) 1e5 + 5] = {0};
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, count = 0;
    for(int r = 0; r < n; r++) {
        freq[a[r]] += 1;
        while(freq[a[r]] > 2) {
            freq[a[r]] -= 1;
            l += 1;
        }
        count += r - l + 1;
    }
    cout << count;
}