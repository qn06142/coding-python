#include <iostream>
#include <vector>

using namespace std;

vector<int> func1(vector<int> arr) {
    vector<int> out;
    for (int i = 0; i < arr.size() - 1; i++) {
        out.push_back(arr[i] + arr[i+1]);
    }
    return out;
}

vector<int> func2(vector<int> arr) {
    vector<int> out;
    for (int i = 0; i < arr.size() - 1; i++) {
        out.push_back(arr[i] * arr[i+1]);
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (a.size() > 1) {
        a = func1(a);
        if (a.size() == 1) {
            break;
        }
        a = func2(a);
    }
    cout << a[0] << endl;
    return 0;
}

