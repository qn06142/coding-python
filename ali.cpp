#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool intersects(double x, double D, double H, const vector<pair<double, double>>& buildings) {
    double m = (H - x) / D;
    for (const auto& building : buildings) {
        double di = building.first;
        double hi = building.second;
        double yi = m * di + x;
        if (yi <= hi) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    double D, H;
    cin >> n >> D >> H;

    vector<pair<double, double>> buildings(n);
    for (int i = 0; i < n; ++i) {
        cin >> buildings[i].first >> buildings[i].second;
    }

    double low = 0.0;
    double high = H;

    while (high - low > 1e-6) {
        double mid = (low + high) / 2.0;
        if (intersects(mid, D, H, buildings)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << fixed << setprecision(6) << high << endl;

    return 0;
}