#include <bits/stdc++.h>
using namespace std;
long long smallestsquare(int n) { 
    long long m = n;
    for (int i = 2; i <= sqrt(n); i = i + 1) { 
        int cnt = 0;
        while (n % i == 0) { 
            cnt ++;
            n = n/i; 
        } 
        if(cnt % 2 == 1) m *= i;
    } 
    if(n != 1) m *= n;
    return m;
} 

int main() {
    long long n;
    cin >> n;
    cout << smallestsquare(n);
    return 0;
}
