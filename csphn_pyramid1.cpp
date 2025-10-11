#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define llu unsigned long long
#define ui unsigned int
#define ld long double
#define ldu unsigned long double
#define pb push_back
#define TASK ""
int n, k, limit; 
int f[27][1000005]; 
string s; 
int calc(int i){ 
    // cerr << "i = " << i << '\n'; 
    if(i % 2 == 0){ 
        // cerr << "(((" << i << "/2))*((" << i << " + 1)))%n" << '\n'; 
        return (((i/2)%n)*((i + 1)%n))%n; 
    } else { 
        // cerr << "((((" << i << "+ 1)/2))*(" << i << "/2))%n" << '\n'; 
        return (((i + 1)/2)%n)*((i%n))%n; 
    }
}
void query2(){ 
    // cout << "Query 2\n"; 
    int i, j; 
    cin >> i >> j; 
    int first_char = (calc(i - 1) + 1)%n; 
    if(first_char == 0) first_char = n; 
    int second_char = (calc(i - 1) + i%n)%n; 
    if(second_char == 0) second_char = n; 
    
    if(i % 2 == 0){ 
        swap(first_char, second_char); 
    }
    // cout << first_char << ' ' << second_char << endl; 
    int ans; 
    if(i % 2 == 0){ 
        ans = (first_char - j + 1)%n; 
    } else { 
        ans = (first_char + j - 1)%n; 
    }
    if(ans < 0) ans += n; 
    if(ans == 0) ans = n; 
    // cout << ans << endl; 
    cout << s[ans] << '\n'; 
}
void query1(){ 
    // cout << "Query 1\n"; 
    int i; char c; 
    cin >> i >> c; 
    int j = c - 'A' + 1; 
    if(i < limit){ 
        // cout << i*(i + 1)/2 << ' ' << (i - 1)*(i)/2 << '\n'; 
        cout << f[j][i*(i + 1)/2] - f[j][(i - 1)*(i)/2] << '\n'; 
    } else { 
        int x = calc(i - 1)%n, ans = 0;
        ans = ans + f[j][n] - f[j][x]; 
        // cout << x << '\n'; 
        // cout << f[j][n] - f[j][x] << '\n'; 
        i -= n - x; 
        ans = ans + (i/n)*(f[j][n]); 
        // cout << (i/n)*(f[j][n]) << '\n'; 
        i -= (i/n)*n; 
        ans = ans + f[j][i]; 
        // cout << f[j][i] << '\n'; 
        cout << ans << '\n'; 
    }

}
void debug(){ 
    cout << "Debug\n"; 
    for(int j = 1; j <= 26; ++j){ 
        cout << (char)('A' + j - 1) << ' '; 
        for(int i = 1; i <= n; ++i){ 
            cout << f[j][i] << ' '; 
        }
        cout << '\n'; 
   }
    
}
void solve(int& tc) {
    // cerr << "Testcase " << tc << '\n';
    cin >> n >> s >> k; 
    n = s.length(); 
    s = " " + s; 

    for(int i = 1; i <= 26; ++i){ 
        for(int j = 1; j <= n; ++j){ 
            if(s[j] == i + 'A' - 1){ 
                f[i][j] = 1; 
            } 
            f[i][j] += f[i][j - 1]; 
        }
    }
    for(int i = 1; i <= 1000; ++i){ 
        if(i*(i + 1)/2 >= n){ 
            limit = i; 
            break; 
        }
    }
    // cout << "Limit " << limit << '\n'; 
    while(k-- > 0){ 
        // cout << "\n Query " << k << '\n'; 
        int num; 
        cin >> num; 
        if(num == 1) query1(); 
        else query2(); 
    }
    // debug(); 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen(TASK".INP", "r", stdin);
    // freopen(TASK".OUT", "w", stdout);
    // freopen("debug.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    // cin.ignore();

    int cnt = 1;
    while (t--) {
        solve(cnt);
        ++cnt; 
    }

    return 0;
}