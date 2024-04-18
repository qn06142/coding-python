#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int max(int a, int b) {
  return (a > b) ? a : b;
}

bool isValid(const vector<int>& assignment, int N) {
  vector<bool> occupied(N, false);
  for (int i = 0; i < N; ++i) {
    if (occupied[assignment[i]]) {
      return false;
    }
    occupied[assignment[i]] = true;
  }
  return true;
}

int calculateEfficiency(const vector<vector<int>>& skills, const vector<int>& assignment, int N) {
  int min_skill = numeric_limits<int>::max();
  for (int i = 0; i < N; ++i) {
    min_skill = min(min_skill, skills[assignment[i]][i]);
  }
  return min_skill;
}

void tryAssignments(const vector<vector<int>>& skills, vector<int>& assignment, int pos, int N, int& bestEfficiency) {
  if (pos == N) {

    if (isValid(assignment, N)) {
      bestEfficiency = max(bestEfficiency, calculateEfficiency(skills, assignment, N));
    }
    return;
  }

  for (int i = 0; i < N; ++i) {
    assignment[pos] = i;
    tryAssignments(skills, assignment, pos + 1, N, bestEfficiency);
  }
}

int main() {
  int N;
  cin >> N;

  vector<vector<int>> skills(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> skills[i][j];
    }
  }

  vector<int> assignment(N, 0);
  int bestEfficiency = -numeric_limits<int>::max();

  tryAssignments(skills, assignment, 0, N, bestEfficiency);

  cout << bestEfficiency << endl;

  return 0;
}