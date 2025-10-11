#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix {
    vector<vector<int>> mat;

    Matrix() {}
    Matrix(int x, int y) {
        mat.assign(x, vector<int>(y, 0));
    }
    Matrix(vector<vector<int>> init) {
        mat = init;
    }
    Matrix(initializer_list<initializer_list<int>> init) {
        for (auto &row : init) mat.emplace_back(row);
    }

    int rows() const { return mat.size(); }
    int cols() const { return mat[0].size(); }

    static Matrix identity(int n) {
        Matrix I(n, n);
        for (int i = 0; i < n; i++) I.mat[i][i] = 1;
        return I;
    }

    Matrix operator* (const Matrix &other) const {
        int n = rows();
        int m = other.cols();
        int k = cols();

        Matrix res(n, m);

        for (int i = 0; i < n; i++) {
            for (int t = 0; t < k; t++) {
                if (mat[i][t] == 0) continue;
                long long val = mat[i][t];
                for (int j = 0; j < m; j++) {
                    if (other.mat[t][j] == 0) continue;
                    res.mat[i][j] = (res.mat[i][j] + (val * other.mat[t][j]) % MOD) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix modular_pow(Matrix base, long long exp) {
    Matrix result = Matrix::identity(base.rows());
    while (exp > 0) {
        if (exp & 1) result = result * base;
        base = base * base;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long k;
    cin >> n >> k;
    vector<int> d(n);
    int M = 0;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        M = max(M, d[i]);
    }

    int S = M + 1;
    Matrix b(S, S);

    for (int x : d) {
        if (x <= M) {

            b.mat[1][x] = (b.mat[1][x] + 1) % MOD;

            b.mat[0][x] = (b.mat[0][x] + 1) % MOD;
        }
    }

    b.mat[0][0] = (b.mat[0][0] + 1) % MOD;

    for (int r = 2; r <= M; ++r) {
        b.mat[r][r-1] = 1;
    }

    Matrix t_(S, 1);
    t_.mat[0][0] = 1; 
    t_.mat[1][0] = 1; 
    for (int i = 2; i < S; ++i) t_.mat[i][0] = 0;

    Matrix P = modular_pow(b, k);
    Matrix R = P * t_;

    cout << R.mat[0][0] % MOD << "\n";
}