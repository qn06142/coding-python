#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Position {
    int row, col, moves;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, K;
    cin >> M >> K;

    vector<int> trackSequence(K);
    for (int i = 0; i < K; ++i) {
        cin >> trackSequence[i];
    }

    vector<string> tracks(2 * M);
    for (int i = 0; i < 2 * M; ++i) {
        cin >> tracks[i];
    }

    int totalColumns = 0;
    vector<int> columnOffsets(K + 1, 0);

    for (int i = 0; i < K; ++i) {
        int trackNumber = trackSequence[i] - 1;
        int numColumns = tracks[2 * trackNumber].size();
        totalColumns += numColumns;
        columnOffsets[i + 1] = totalColumns;
    }

    vector<string> testTrack(2, string(totalColumns, '#'));

    for (int i = 0; i < K; ++i) {
        int trackNumber = trackSequence[i] - 1;
        int startCol = columnOffsets[i];
        int endCol = columnOffsets[i + 1];

        for (int j = 0; j < 2; ++j) {
            for (int col = startCol; col < endCol; ++col) {
                testTrack[j][col] = tracks[2 * trackNumber + j][col - startCol];
            }
        }
    }

    vector<vector<bool>> visited(2, vector<bool>(totalColumns, false));
    queue<Position> q;

    for (int row = 0; row < 2; ++row) {
        if (testTrack[row][0] == '.') {
            q.push({row, 0, 0});
            visited[row][0] = true;
        }
    }

    int minMoves = -1;

    while (!q.empty()) {
        Position curr = q.front();
        q.pop();

        if (curr.col == totalColumns - 1) {
            minMoves = curr.moves;
            break;
        }

        if (curr.row == 0 && !visited[1][curr.col] && testTrack[1][curr.col] == '.') {
            visited[1][curr.col] = true;
            q.push({1, curr.col, curr.moves + 1});
        }
        if (curr.row == 1 && !visited[0][curr.col] && testTrack[0][curr.col] == '.') {
            visited[0][curr.col] = true;
            q.push({0, curr.col, curr.moves + 1});
        }

        if (curr.col + 1 < totalColumns && !visited[curr.row][curr.col + 1] && testTrack[curr.row][curr.col + 1] == '.') {
            visited[curr.row][curr.col + 1] = true;
            q.push({curr.row, curr.col + 1, curr.moves + 1});
        }
    }

    cout << minMoves << '\n';

    return 0;
}
