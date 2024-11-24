#include <bits/stdc++.h>
using namespace std;

bool check(int n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;

}
int main() {
    int n; cin >> n;
    int m = 1;
    while (check(n * m  + 1)){
        m++;
    }
    cout << m;
    return 0;
}