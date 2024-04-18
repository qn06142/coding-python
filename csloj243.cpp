#include<iostream>
#include<algorithm>
using namespace std;
int a[(int) 1e5 + 5], b[(int) 1e5 + 5];
int main() {
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int i = 0, j = 0;
    sort(a, a + m); // sort array a with size m
    sort(b, b + n); // sort array b with size n
    int count = 0;
    while(i < m && j < n) { // iterate until either i or j reach the end of their respective arrays
        if(a[i] > b[j]) { // if the height of the boy is greater than the height of the girl
            count++; // increment the count of pairs
            i++; // move to the next boy
            j++; // move to the next girl
        } else { // if the height of the boy is not greater than the height of the girl
            i++; // move to the next boy
        }
    }
    cout << count;
    return 0;
}
