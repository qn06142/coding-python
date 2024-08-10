#include <iostream>
#include <vector>
using namespace std;

void bacctracc(int n, char from, char to, char aux, vector<pair<char, char>>& moves) {
    if (n == 0) return;
    bacctracc(n - 1, from, aux, to, moves); 
    moves.push_back({from, to});        
    bacctracc(n - 1, aux, to, from, moves); 
}

int main() {
    int n;
    cin >> n;

    vector<pair<char, char>> moves;

    bacctracc(n, '1', '3', '2', moves); 

    cout << moves.size() << endl; 

    for (const auto& move : moves) {
        cout << move.first << " " << move.second << endl; 
    }

    return 0;
}