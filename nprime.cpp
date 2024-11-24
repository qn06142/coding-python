#include<iostream>
#include<cmath>
using namespace std;
bool isnigger(long long x) {
    if(x <= 1) return false;
    if(x == 2) return true;
    for(long long i = 2; i <= ceil(sqrt(x)); i++) if(x % i == 0) return false;
    return true; 
}

int main() {
    long long n;
    cin >> n;
    long long d = ceil(sqrt(n));
    while(!isnigger(d)) d++;
    cout << d * d;
}