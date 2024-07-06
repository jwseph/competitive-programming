#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = LLONG_MAX/2;

using Row = vector<ll>;
struct Matrix: public vector<Row> {
    static constexpr ll z = inf, o = 0;
    int n, m;
    Matrix(int n, int m): n(n), m(m), vector<Row>(n, Row(m, z)) {};
    Matrix(initializer_list<Row> l): vector<Row>(l) {};
    friend Matrix operator*(const Matrix& a, const Matrix& b) {
        int k = a[0].size(), n = a.size(), m = b[0].size();
        if (k != b.size()) cout << "invalid product dimensions" << endl;
        Matrix p(n, m);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                for (int i = 0; i < n; ++i) {
                    p[r][c] = min(p[r][c], a[r][i]+b[i][c]);
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

int n, m, k;

int main() {
    cin >> n >> m >> k;
    Matrix ds(n+1, n+1);
    while (m--) {
        int i, j; ll w; cin >> i >> j >> w;
        ds[i][j] = min(ds[i][j], w);
    }
    ll res = (ds^k)[1][n];
    cout << (res < inf ? res : -1) << endl;
}