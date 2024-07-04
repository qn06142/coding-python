#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 5e5 + 7;

int n, k, a[N], cnt[N];
multiset<int> L, R;

int get_max(multiset<int>& s) {
    return *s.rbegin();
}

int get_min(multiset<int>& s) {
    return *s.begin();
}

void add(int x) {
    L.insert(x);
    if ((int)L.size() > k / 2) {
        int maxL = get_max(L);
        L.erase(L.find(maxL));
        R.insert(maxL);
    }
}

void del(int x) {
    if (L.find(x) != L.end()) {
        L.erase(L.find(x));
        int minR = get_min(R);
        L.insert(minR);
        R.erase(R.begin());
    } else {
        R.erase(R.find(x));
    }
}

int get_median() {
    if (L.size() == R.size()) return *L.rbegin();
    return *R.begin();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= k; i++) add(a[i]);
    cnt[get_median()]++;
    
    for (int i = k + 1; i <= n; i++) {
        del(a[i - k]);
        add(a[i]);
        cnt[get_median()]++;
    }
    
    for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
    
    return 0;
}