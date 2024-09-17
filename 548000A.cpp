#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    
    long long x1, y1, x2, y2;
    scanf("%lld %lld", &x1, &y1);
    scanf("%lld %lld", &x2, &y2);
    
    long long min_steps = max(abs(x2 - x1), abs(y2 - y1));

    printf("%lld\n", min_steps);
    
    return 0;
}
