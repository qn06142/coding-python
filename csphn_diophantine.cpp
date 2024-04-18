#include<bits/stdc++.h>
using namespace std;
long long gcdex(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcdex(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	long long a, b, c, x, y, count = 0;
	cin >> a >> b >> c;
	long long d = gcdex(a, b, x, y);
	long long t1 = -((c * x)/b), t2 = (c * y)/a;
	for(long long i = t1; i <= t2; i++) {
		long long x1 = (c * x)/d + b/d * i;
		long long y1 = (c * y)/d - a/d * i;
		if (a * x1 + b * y1 == c and x1 > 0 and y1 > 0) {
			count++;
		}
	}
	cout << count;
}