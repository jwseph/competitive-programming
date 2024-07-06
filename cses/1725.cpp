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

Matrix recur(int n) {
    Matrix x(n, n);
    for (int i = 0; i < n; ++i) {
        for (int p = i-1; p >= i-6 && p >= 0; --p) {
            x[i][p] = 1/6.;
        }
    }
    return x;
}

int n, a, b;

int main() {
    cin >> n >> a >> b;
    Matrix x = recur(6*n+1), x0(6*n+1, 1);
    x0[0][0] = 1;
    Matrix y = (x^n)*x0;
    double res = 0;
    for (int i = a; i <= b; ++i) res += y[i][0];
    cout << fixed << setprecision(6) << round(res*1e6)/1e6 << endl;
}