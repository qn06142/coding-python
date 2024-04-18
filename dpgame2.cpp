#include<bits/stdc++.h>
using namespace std;
int gleft[1000005], gright[1000005], a[1000005];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n ; i++) cin >> a[i];
	gleft[0] = a[0];
	for(int i = 1; i < n; i++) {
		gleft[i] = gcd(a[i], gleft[i-1]);
	}
	for(int i = n; i >= 1; i++) {
		gright[i] = gcd(a[i], gright[i+1]);
	}

}