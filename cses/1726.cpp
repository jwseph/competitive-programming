#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Matrix: public vector<vector<double>> {
    using T = double;
    static constexpr T z = 0, o = 1;
    static T upd(T a, T b) { return a+b; }
    static T con(T a, T b) { return a*b; }
    int n, m;
    using R = vector<T>;
    Matrix(int n, int m): n(n), m(m), vector<R>(n, R(m, z)) {};
    Matrix(initializer_list<R> l): vector<R>(l) {};
    friend Matrix operator*(const Matrix& a, const Matrix& b) {
        int k = a[0].size(), n = a.size(), m = b[0].size();
        if (k != b.size()) cout << "invalid product dimensions" << endl;
        Matrix p(n, m);
        for (int r = 0; r < n; ++r) {
            for (int i = 0; i < n; ++i) {
                if (a[r][i] == z) continue;
                for (int c = 0; c < m; ++c) {
                    p[r][c] = upd(p[r][c], con(a[r][i], b[i][c]));
                }
            }
        }
        return p;
    }
    friend Matrix operator^(Matrix x, ll b) {
        int n = x.size();
        Matrix r(n, n);
        for (int i = 0; i < n; ++i) r[i][i] = o;
        while (b) {
            if (b&1) r = r*x;
            x = x*x;
            b >>= 1;
        }
        return r;
    }
};

const int N = 8;
int n = N, k;
vector<int> ad[N*N];

const int dr[4] = {0, -1, 0, 1}, dc[4] = {1, 0, -1, 0};

Matrix recur() {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            for (int d = 0; d < 4; ++d) {
                int i = r+dr[d], j = c+dc[d];
                if (i < 0 || i >= n || j < 0 || j >= n) continue;
                ad[r*n+c].push_back(i*n+j);
            }
        }
    }
    Matrix x(n*n, n*n);
    for (int i = 0; i < n*n; ++i) {
        for (int j: ad[i]) {
            x[i][j] = 1./ad[j].size();
        }
    }
    return x;
}

int main() {
    cin >> k;
    Matrix x = recur()^k;
    vector<double> em(n*n, 1);
    for (int r = 0; r < n*n; ++r) {
        Matrix a(n*n, 1);
        a[r][0] = 1;
        Matrix y = x*a;
        for (int p = 0; p < n*n; ++p) {
            em[p] *= (1-y[p][0]);
        }
    }
    double res = 0;
    for (double p: em) res += p;
    cout << fixed << setprecision(6) << res << endl;
}