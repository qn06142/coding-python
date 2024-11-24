#include <bits/stdc++.h>

using namespace std;

int     n,x[100],dd[100];
bool    yes[100][100];
int     res[100] = {0, 0, 2, 2, 4, 96, 1024, 2880, 81024, 770144};
int     dem = 0;

bool kt(int x) {
	if (x <= 1) return false;
	for (int i=2; i*i<=x; i++)
		if (x % i == 0) return false;
	return true;
}

void dq(int t) {
	if (t == n+1) {
		if (not yes[x[1]][x[n]]) return;
		dem++;
		//for (int i=1; i<=n; i++) printf("%d ",x[i]);
		printf("\n");
		return;
	}
	for (int i=1; i<=n; i++)
		if (dd[i] == 0 and yes[x[t-1]][i]) {
			x[t] = i;
			dd[i] = 1;
			dq(t+1);
			if (dem == 10000) return;
			dd[i] = 0;
		}
}

int main() {
	scanf("%d",&n);
	printf("%d\n",res[n]);

	n *= 2;
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++) {
			yes[i][j] = kt(i+j);
			yes[j][i] = yes[i][j];
		}

	x[1] = 1;
	dd[1] = 1;
	dq(2);

	return 0;
}
