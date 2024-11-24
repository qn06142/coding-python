#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n = 10;
bool a[1000][1000];
void printSolution(bool board[1000][1000])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << " "<< board[i][j];
        cout << endl;
    }
}

bool usedcol[1000], usedrow[1000], useddiag1[2000], useddiag2[2000];
void bacctracc(int i) {
	
	for (int r = 1; r <= n; r++) {
		for (int l = 1; l <= n; l++) {
			if (!usedcol[l] && !usedrow[r] && !useddiag1[l-r+n] && !useddiag2[l+r]) {
				a[r][l] = true;
				if (i == n) {
					printSolution(a);
					cout << endl;
					a[r][l] = false;
				} else {
					usedcol[l] =usedrow[r] =useddiag1[l-r+n] =useddiag2[l+r] = true;
					bacctracc(i +1);
					usedcol[l] =usedrow[r] =useddiag1[l-r+n] =useddiag2[l+r] = false;
					a[r][l] = false;
				}
			}
		}
	}
}
int main() {
	memset(a,false,sizeof(a));
	cin >> n;
	bacctracc(1);
}
