#include<iostream>
#include<algorithm>
using namespace std;
int a[(int) 1e6  +5];
int main() {
    int n;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << *min_element(a + 1, a + 1 + n);
}