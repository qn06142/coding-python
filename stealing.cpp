#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN];
int pos[MAXN];
bool avail[MAXN];
int owner[MAXN];
int prev_[MAXN], next_[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
        avail[i] = true;
        prev_[i] = i - 1;
        next_[i] = i + 1;
    }

    int currentThief = 1;
    int remaining = n;
    int maxValue = n;
    while (remaining > 0) {
        // Find the highest available value
        
        
        for(int i = maxValue; i >= 1; i--) {
            if(avail[pos[i]]) {
                maxValue = i;
                break;
            }
        }
        int maxIndex = pos[maxValue];
        // Assign the items to the current thief
        int cnt1 = 0;
        avail[maxIndex] = false;
        owner[maxIndex] = currentThief;
        remaining--;
        int lasttaken;
        for(lasttaken = next_[maxIndex]; lasttaken <= n; lasttaken = next_[lasttaken]) {
            if(cnt1 == k) {
                break;
            }
            if(avail[lasttaken]) {
                cnt1++;
                avail[lasttaken] = false;
                owner[lasttaken] = currentThief;
                --remaining;
            }
            //cerr << i << " first" << endl;
        }
        int firsttaken;
        cnt1 = 0;
        for(firsttaken = prev_[maxIndex]; firsttaken >= 1; firsttaken = prev_[firsttaken]) {
            if(cnt1 == k) {
                break;
            }
            if(avail[firsttaken]) {
                cnt1++;
                avail[firsttaken] = false;
                owner[firsttaken] = currentThief;
                --remaining;
            }
            
            //cerr << i << " second" << endl;
        }
        next_[firsttaken] = lasttaken;
        prev_[lasttaken] = firsttaken;

        // Switch to the other thief
        currentThief = 3 - currentThief;
    }

    for (int i = 1; i <= n; ++i) {
        cout << owner[i];
    }
    cout << '\n';

    return 0;
}
