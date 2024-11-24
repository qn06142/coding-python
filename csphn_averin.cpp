#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i =0; i < n; i++) {
		cin >> a[i];
	}
	int sum = 0;
	int count = 0;
	int avg;
	for (int i = 0; i < n; i++) {
		count = 0;
		for (int j = i; j < n; j++){
			sum += a[j];
			if (sum %(j-i+1) == 0) {
				avg = sum / (j-i + 1);
				int afind[j-i + 1];
				for (int k = i; k <= j; k++) {
					afind[k- i] = a[k];
				}
				if (find(afind.begin(), afind.end(), avg) != afind.end()) {
					count += 1
				}
			}
		}
	}
	cout << count;
}
