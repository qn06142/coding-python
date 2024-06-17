#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n;
int A[MAXN]; // Assuming A is populated with the food types converted to integers
int DP[2][4][4][4][4];

// Function to calculate unique food types
int t( int a, int b, int c ){
	int ret = 0;
	for( int i = 1; i <= 3; i++ )
		if( a == i || b == i || c == i )
			ret++;
	return ret;
}// Function to convert food character to index
int food_to_index(char food) {
    if (food == 'M') return 1;
    if (food == 'F') return 2;
    if (food == 'B') return 3;
    return -1; // Invalid food character
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char food;
        cin >> food;
        A[i] = food_to_index(food); // Convert food character to index
    }
    int a = 0, b = 1;
    DP[0][0][0][0][0] = 0; // Base case
    for(int i = n; i; i-- ){
		swap( a, b );
		for(int x = 0; x < 4; x++ )
			for(int y = 0; y < 4; y++ )
				for(int r = 0; r < 4; r++ )
					for(int s = 0; s < 4; s++ )
						DP[a][x][y][r][s] = max( DP[b][y][ A[i] ][r][s] + t( x, y, A[i] ), DP[b][x][y][s][ A[i] ] + t( r, s, A[i] ) );
	}
	cout << DP[a][0][0][0][0] << "\n";

    return 0;
}

