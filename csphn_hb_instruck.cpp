#include<iostream>
#include<cmath>

using namespace std;

int getval(int x) {
    long long l, r, mid;
    l = 1;
    r = 1e10;
    while(l < r) {
        mid = (l + r) / 2;
        if((mid*(mid + 1) / 2) >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
long long calc1(int x) {
    return x * (x + 1) * (2 * x - 1) / 6;
}
long long calc(int l,int r) {
    return calc1(r) - calc1(l - 1);
}
int main() {
    long long a, b;
    cin >> a >> b;
    long long tmp, tmp1;
    tmp = getval(a + 1);
    tmp1 = getval(b - 1);
    long long ans = 0;
    ans += calc(tmp, tmp1);
    //if both is in same part
    if(tmp == tmp1) {
        
    }
}
//1 2 2 3 3 3 4 4 4 4 5 5 5 5 5