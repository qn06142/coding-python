#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define int long long
struct Animal {
    string species;
    int influence;
};

signed main() {
    int n;
    cin >> n;
    vector<Animal> animals(n);

    for (int i = 0; i < n; ++i) {
        cin >> animals[i].species >> animals[i].influence;
    }

    int max_pig_influence = -1;
    bool pig_found = false;

    for (int i = 0; i < n; ++i) {
        if (animals[i].species == "pig") {
            if (animals[i].influence > max_pig_influence) {
                max_pig_influence = animals[i].influence;
                pig_found = true;
            }
        }
    }

    if (!pig_found) {

        cout << 0 << endl;
        return 0;
    }

    int total_influence = max_pig_influence;  
    for (int i = 0; i < n; ++i) {
        if (animals[i].species != "pig" && animals[i].influence < max_pig_influence) {
            total_influence += animals[i].influence;
        }
    }

    cout << total_influence << endl;

    return 0;
}